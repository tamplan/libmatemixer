/*
 * Copyright (C) 2014 Michal Ratajsky <michal.ratajsky@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the licence, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MATEMIXER_CONTROL_H
#define MATEMIXER_CONTROL_H

#include <glib.h>
#include <glib-object.h>

#include <libmatemixer/matemixer-enums.h>
#include <libmatemixer/matemixer-stream.h>

G_BEGIN_DECLS

#define MATE_MIXER_TYPE_CONTROL                 \
        (mate_mixer_control_get_type ())
#define MATE_MIXER_CONTROL(o)                   \
        (G_TYPE_CHECK_INSTANCE_CAST ((o), MATE_MIXER_TYPE_CONTROL, MateMixerControl))
#define MATE_MIXER_IS_CONTROL(o)                \
        (G_TYPE_CHECK_INSTANCE_TYPE ((o), MATE_MIXER_TYPE_CONTROL))
#define MATE_MIXER_CONTROL_CLASS(k)             \
        (G_TYPE_CHECK_CLASS_CAST ((k), MATE_MIXER_TYPE_CONTROL, MateMixerControlClass))
#define MATE_MIXER_IS_CONTROL_CLASS(k)          \
        (G_TYPE_CLASS_CHECK_CLASS_TYPE ((k), MATE_MIXER_TYPE_CONTROL))
#define MATE_MIXER_CONTROL_GET_CLASS(o)         \
        (G_TYPE_INSTANCE_GET_CLASS ((o), MATE_MIXER_TYPE_CONTROL, MateMixerControlClass))

typedef struct _MateMixerControl         MateMixerControl;
typedef struct _MateMixerControlClass    MateMixerControlClass;
typedef struct _MateMixerControlPrivate  MateMixerControlPrivate;

struct _MateMixerControl
{
    GObject parent;

    MateMixerControlPrivate *priv;
};

struct _MateMixerControlClass
{
    GObjectClass parent;
};

GType mate_mixer_control_get_type (void) G_GNUC_CONST;

MateMixerControl *    mate_mixer_control_new                       (void);
MateMixerControl *    mate_mixer_control_new_backend               (MateMixerBackendType  backend_type);
const GList *         mate_mixer_control_list_devices              (MateMixerControl     *control);
const GList *         mate_mixer_control_list_streams              (MateMixerControl     *control);
MateMixerStream  *    mate_mixer_control_get_default_input_stream  (MateMixerControl     *control);
MateMixerStream  *    mate_mixer_control_get_default_output_stream (MateMixerControl     *control);
const gchar *         mate_mixer_control_get_backend_name          (MateMixerControl     *control);
MateMixerBackendType  mate_mixer_control_get_backend_type          (MateMixerControl     *control);

G_END_DECLS

#endif /* MATEMIXER_CONTROL_H */