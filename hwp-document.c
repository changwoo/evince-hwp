/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * hwp-document.c
 * Copyright (C) Hodong Kim 2012 <cogniti@gmail.com>
 * 
hwp-document.c is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * hwp-document.c is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.";
 */

#include "config.h"

#include <libghwp/ghwp.h>

#include "hwp-document.h"


struct _HWPDocument
{
	EvDocument object;

	GFile        *file;
	GHWPFile     *hwp;
	GHWPDocument *doc;
};

struct _HWPDocumentClass
{
	EvDocumentClass parent_class;
};

EV_BACKEND_REGISTER (HWPDocument, hwp_document);

static void
hwp_document_init (HWPDocument *hwp_document)
{
	printf("hwp_document_init\n");
}

static void
hwp_document_dispose (GObject *object)
{
	HWPDocument *hwp = HWP_DOCUMENT (object);

	if (hwp->file) {
		g_object_unref (hwp->file);
		hwp->file = NULL;
	}

	if (hwp->hwp) {
		g_object_unref (hwp->hwp);
		hwp->hwp = NULL;
	}

	if (hwp->doc) {
		g_object_unref (hwp->doc);
		hwp->doc = NULL;
	}

	G_OBJECT_CLASS (hwp_document_parent_class)->dispose (object);
}

static gboolean
hwp_document_load (EvDocument *document,
		      const char *uri,
		      GError    **error)
{
	HWPDocument *hwp = HWP_DOCUMENT (document);
	printf("hwp_document_load\n");
	hwp->file = g_file_new_for_uri (uri);
	printf("%s\n", uri);
	hwp->hwp = ghwp_file_new (hwp->file, error);

	if (!hwp->hwp)
		return FALSE;

	/* FIXME: what if there are multiple docs? */
	printf("hwp-document.c: ghwp_file_get_document\n");
	hwp->doc = ghwp_file_get_document (hwp->hwp, 0, error);

	if (!hwp->doc) {
		g_object_unref (hwp->hwp);
		hwp->hwp = NULL;

		return FALSE;
	}

	return TRUE;
}

static int
hwp_document_get_n_pages (EvDocument  *document)
{
	HWPDocument *hwp = HWP_DOCUMENT (document);
	printf("hwp_document_get_n_pages\n");

	return ghwp_document_get_n_pages (hwp->doc);
}

static EvPage *
hwp_document_get_page (EvDocument *document,
		       gint        index)
{
	HWPDocument *hwp = HWP_DOCUMENT (document);
	GHWPPage    *hwp_page;
	EvPage      *page;

	hwp_page = ghwp_document_get_page (hwp->doc, index, NULL);
	page = ev_page_new (index);
	if (hwp_page) {
		page->backend_page = (EvBackendPage)hwp_page;
		page->backend_destroy_func = (EvBackendPageDestroyFunc)g_object_unref;
	}

	return page;
}

static void
hwp_document_get_page_size (EvDocument *document,
			     EvPage     *page,
			     double     *width,
			     double     *height)
{
	ghwp_page_get_size (GHWP_PAGE (page->backend_page), width, height);
}

static cairo_surface_t *
hwp_document_render (EvDocument      *document,
		      EvRenderContext *rc)
{
	GHWPPage        *hwp_page;
	gdouble          page_width, page_height;
	guint            width, height;
	cairo_surface_t *surface;
	cairo_t         *cr;
	GError          *error = NULL;

	hwp_page = GHWP_PAGE (rc->page->backend_page);

	ghwp_page_get_size (hwp_page, &page_width, &page_height);
	if (rc->rotation == 90 || rc->rotation == 270) {
		width = (guint) ((page_height * rc->scale) + 0.5);
		height = (guint) ((page_width * rc->scale) + 0.5);
	} else {
		width = (guint) ((page_width * rc->scale) + 0.5);
		height = (guint) ((page_height * rc->scale) + 0.5);
	}

	surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32,
					      width, height);
	cr = cairo_create (surface);

	cairo_set_source_rgb (cr, 1., 1., 1.);
	cairo_paint (cr);

	switch (rc->rotation) {
	case 90:
		cairo_translate (cr, width, 0);
		break;
	case 180:
		cairo_translate (cr, width, height);
		break;
	case 270:
		cairo_translate (cr, 0, height);
		break;
	default:
		cairo_translate (cr, 0, 0);
	}

	cairo_scale (cr, rc->scale, rc->scale);
	cairo_rotate (cr, rc->rotation * G_PI / 180.0);
	ghwp_page_render (hwp_page, cr, &error);
	cairo_destroy (cr);

	if (error) {
		g_warning ("Error rendering page %d: %s\n",
			   rc->page->index, error->message);
		g_error_free (error);
	}

	return surface;
}

static void
hwp_document_class_init (HWPDocumentClass *klass)
{
	GObjectClass    *gobject_class = G_OBJECT_CLASS (klass);
	EvDocumentClass *ev_document_class = EV_DOCUMENT_CLASS (klass);
	printf("hwp_document_class_init\n");
	gobject_class->dispose = hwp_document_dispose;

	ev_document_class->load = hwp_document_load;
	ev_document_class->get_n_pages = hwp_document_get_n_pages;
	ev_document_class->get_page = hwp_document_get_page;
	ev_document_class->get_page_size = hwp_document_get_page_size;
	ev_document_class->render = hwp_document_render;
}
