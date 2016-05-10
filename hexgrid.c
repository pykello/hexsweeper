#include "hexgrid.h"

typedef struct {
	int size;
	int button_size;
} GtkHexGridPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (GtkHexGrid, gtk_hexgrid, GTK_TYPE_LAYOUT)

GtkWidget * gtk_hexgrid_new (gint size, gint button_size)
{
	GtkWidget * hexgrid = g_object_new (GTK_TYPE_HEXGRID, NULL);
	GtkHexGridPrivate *priv = gtk_hexgrid_get_instance_private (GTK_HEXGRID (hexgrid));
	priv->size = size;
	priv->button_size = button_size;
	return hexgrid;
}

static void
gtk_hexgrid_get_preferred_width (GtkWidget *widget,
                                gint      *minimum,
                                gint      *natural)
{
	GtkHexGridPrivate *priv = gtk_hexgrid_get_instance_private (GTK_HEXGRID (widget));
	gint width = 2 * priv->size * priv->button_size;
	*minimum = width;
	*natural = width;
}

static void
gtk_hexgrid_get_preferred_height (GtkWidget *widget,
                                gint      *minimum,
                                gint      *natural)
{
	GtkHexGridPrivate *priv = gtk_hexgrid_get_instance_private (GTK_HEXGRID (widget));
	gint height = (4 * priv->size - 2) * priv->button_size;
	*minimum = height;
	*natural = height;
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

	widget_class->get_preferred_height = gtk_hexgrid_get_preferred_width;
	widget_class->get_preferred_width = gtk_hexgrid_get_preferred_height;

	container_class->add = gtk_hexgrid_add;
}

static void
gtk_hexgrid_init (GtkHexGrid *hexgrid)
{
}
