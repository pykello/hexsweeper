#ifndef __HEXBUTTON_H__
#define __HEXBUTTON_H__

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define GTK_TYPE_HEXBUTTON (gtk_hexbutton_get_type ())
#define GTK_HEXBUTTON(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_HEXBUTTON, GtkHexButton))

typedef struct _GtkHexButton             GtkHexButton;
typedef struct _GtkHexButtonClass        GtkHexButtonClass;

struct _GtkHexButton {
  GtkButton parent_instance;
};

struct _GtkHexButtonClass {
  GtkButtonClass parent_class;
};

GtkWidget * gtk_hexbutton_new(void);
GType gtk_hexbutton_get_type (void) G_GNUC_CONST;

G_END_DECLS

#endif
