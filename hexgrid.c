#include "hexgrid.h"
#include <stdlib.h>

#define P(hexgrid) ((GtkHexGridPrivate *)\
		    gtk_hexgrid_get_instance_private (GTK_HEXGRID (hexgrid)))

typedef struct {
	int size;
	int button_size;
	int width, height;
} GtkHexGridPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (GtkHexGrid, gtk_hexgrid, GTK_TYPE_LAYOUT)

GtkWidget * gtk_hexgrid_new (gint size, gint button_size)
{
	GtkWidget * hexgrid = g_object_new (GTK_TYPE_HEXGRID, NULL);
	P(hexgrid)->size = size;
	P(hexgrid)->button_size = button_size;
	P(hexgrid)->width = (3 * size - 1) * button_size;
	P(hexgrid)->height = 2 * button_size * (2 * size - 1);
	return hexgrid;
}

void gtk_hexgrid_put(GtkHexGrid* hexgrid, GtkWidget* child, int x, int y)
{
	int real_x = P(hexgrid)->width / 2 - P(hexgrid)->button_size +
		     3 * x * P(hexgrid)->button_size / 2;
	int real_y = abs(x) * (P(hexgrid)->button_size + 1) +
		     2 * y * P(hexgrid)->button_size;

	gtk_widget_set_size_request(child, 2 * P(hexgrid)->button_size,
				    P(hexgrid)->button_size * 2);
	gtk_layout_put(GTK_LAYOUT(hexgrid), child, real_x, real_y);
}

static void gtk_hexgrid_get_preferred_width(GtkWidget *widget, gint *minimum,
					    gint *natural)
{
	if (minimum) *minimum = P(widget)->width;
	if (natural) *natural = P(widget)->width;
}

static void gtk_hexgrid_get_preferred_height (GtkWidget *widget, gint *minimum,
					      gint *natural)
{
	if (minimum) *minimum = P(widget)->height;
	if (natural) *natural = P(widget)->height;
}

static void gtk_hexgrid_class_init (GtkHexGridClass *klass)
{
	GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);
	widget_class->get_preferred_height = gtk_hexgrid_get_preferred_height;
	widget_class->get_preferred_width = gtk_hexgrid_get_preferred_width;
}

static void gtk_hexgrid_init (GtkHexGrid *hexgrid)
{
}
