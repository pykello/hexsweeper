#include "hexgrid.h"
#include <stdlib.h>

typedef struct {
	int size;
	int button_size;
	int width, height;
} GtkHexGridPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (GtkHexGrid, gtk_hexgrid, GTK_TYPE_LAYOUT)

GtkWidget * gtk_hexgrid_new (gint size, gint button_size)
{
	GtkWidget * hexgrid = g_object_new (GTK_TYPE_HEXGRID, NULL);
	GtkHexGridPrivate *priv = gtk_hexgrid_get_instance_private (GTK_HEXGRID (hexgrid));
	priv->size = size;
	priv->button_size = button_size;
	priv->width = (3 * size - 1) * button_size;
	priv->height = 2 * button_size * (2 * size - 1);
	return hexgrid;
}

void
gtk_hexgrid_put(GtkHexGrid* grid, GtkWidget* child, int x, int y)
{
	int real_x, real_y;
	GtkHexGridPrivate *priv = gtk_hexgrid_get_instance_private (GTK_HEXGRID (grid));
	int width = priv->width;
	int height = priv->height;

	gtk_widget_set_size_request (child, priv->button_size * 2, priv->button_size * 2);

	real_x = (width / 2) - priv->button_size + x * (3 * priv->button_size / 2);
	real_y = abs(x) * (priv->button_size + 1) + 2 * y * priv->button_size;
	
	gtk_layout_put(GTK_LAYOUT(grid), child, real_x, real_y);
}

static void
gtk_hexgrid_get_preferred_width (GtkWidget *widget,
                                gint      *minimum,
                                gint      *natural)
{
	GtkHexGridPrivate *priv = gtk_hexgrid_get_instance_private (GTK_HEXGRID (widget));
	if (minimum) *minimum = priv->width;
	if (natural) *natural = priv->width;
}

static void
gtk_hexgrid_get_preferred_height (GtkWidget *widget,
                                gint      *minimum,
                                gint      *natural)
{
	GtkHexGridPrivate *priv = gtk_hexgrid_get_instance_private (GTK_HEXGRID (widget));
	if (minimum) *minimum = priv->height;
	if (natural) *natural = priv->height;
}

static void
gtk_hexgrid_add (GtkContainer *container, GtkWidget *child)
{
	GtkHexGridPrivate *priv = gtk_hexgrid_get_instance_private (GTK_HEXGRID (container));
	gtk_layout_put(GTK_LAYOUT(container), child, 10, 10);
}

static void
gtk_hexgrid_class_init (GtkHexGridClass *klass)
{
	GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);
	GtkContainerClass *container_class = GTK_CONTAINER_CLASS (klass);
	g_print("init ...\n");

	widget_class->get_preferred_height = gtk_hexgrid_get_preferred_height;
	widget_class->get_preferred_width = gtk_hexgrid_get_preferred_width;

	container_class->add = gtk_hexgrid_add;
}


static void
gtk_hexgrid_init (GtkHexGrid *hexgrid)
{
}
