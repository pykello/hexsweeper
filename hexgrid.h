#ifndef __HEXGRID_H__
#define __HEXGRID_H__

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define GTK_TYPE_HEXGRID (gtk_hexgrid_get_type ())
#define GTK_HEXGRID(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_HEXGRID, GtkHexGrid))

typedef struct _GtkHexGrid             GtkHexGrid;
typedef struct _GtkHexGridClass        GtkHexGridClass;

struct _GtkHexGrid {
  GtkLayout parent_instance;
};

struct _GtkHexGridClass {
  GtkLayoutClass parent_class;
};

GtkWidget * gtk_hexgrid_new (gint size, gint button_size);
GType gtk_hexgrid_get_type (void) G_GNUC_CONST;

G_END_DECLS

#endif
