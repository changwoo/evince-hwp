/*
 * hwp-document.h
 *
 * Copyright (C) 2012  Hodong Kim <cogniti@gmail.com>
 * 
 * hwp-document.h is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * hwp-document.h is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __HWP_DOCUMENT_H__
#define __HWP_DOCUMENT_H__

#include <glib-object.h>

#include <evince-document.h>


G_BEGIN_DECLS

#define HWP_TYPE_DOCUMENT            (hwp_document_get_type ())
#define HWP_DOCUMENT(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), HWP_TYPE_DOCUMENT, HWPDocument))
#define HWP_DOCUMENT_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass),  HWP_TYPE_DOCUMENT, HWPDocumentClass))
#define HWP_IS_DOCUMENT(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), HWP_TYPE_DOCUMENT))
#define HWP_IS_DOCUMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  HWP_TYPE_DOCUMENT))
#define HWP_DOCUMENT_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj),  HWP_TYPE_DOCUMENT, HWPDocumentClass))

typedef struct _HWPDocument      HWPDocument;
typedef struct _HWPDocumentClass HWPDocumentClass;

GType hwp_document_get_type (void) G_GNUC_CONST;

G_MODULE_EXPORT GType register_evince_backend (GTypeModule *module);

G_END_DECLS

#endif /* __HWP_DOCUMENT_H__ */