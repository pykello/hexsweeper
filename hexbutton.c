#include "hexbutton.h"

#define RGB(r, g, b) { (r)/255.0, (g)/255.0, (b)/255., 1.0 }

typedef struct {
	gboolean down;
} GtkHexButtonPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (GtkHexButton, gtk_hexbutton, GTK_TYPE_BUTTON)

static void
draw_outline (cairo_t *cr,
	      GdkRGBA* top_color,
	      GdkRGBA* bottom_color,
	      int      x,
	      int      y,
	      int      width,
	      int      height)
{
  GdkRGBA rgba;
  gdk_cairo_set_source_rgba (cr, top_color);
  cairo_move_to(cr, (3 * width) / 4, 0);
  cairo_rel_line_to(cr, -width / 2, 0);
  cairo_rel_line_to(cr, -width / 4, height / 2);
  cairo_rel_line_to(cr, width / 4, height / 2);
  cairo_stroke(cr);

  gdk_cairo_set_source_rgba (cr, bottom_color);
  cairo_move_to(cr, (3 * width) / 4 - 2, 0);
  cairo_rel_line_to(cr, width / 4, height / 2);
  cairo_rel_line_to(cr, -width / 4, height / 2);
  cairo_rel_line_to(cr, -width / 2, 0);
  cairo_stroke(cr);
}

GtkWidget * gtk_hexbutton_new(void)
{
	return g_object_new (GTK_TYPE_HEXBUTTON, NULL);
}

static gboolean
gtk_hexbutton_draw (GtkWidget *widget,
		 cairo_t   *cr)
{
	GtkHexButton *hexbutton = GTK_HEXBUTTON (widget);
	GtkHexButtonPrivate *priv = gtk_hexbutton_get_instance_private (hexbutton);

	gint width, height;
	gtk_widget_get_preferred_width (widget, NULL, &width);
	gtk_widget_get_preferred_height (widget, NULL, &height);

	if (!priv->down) {
		GdkRGBA top_color = RGB(255, 255, 255);
		GdkRGBA bottom_color = RGB(64, 64, 64);
		draw_outline(cr, &top_color, &bottom_color, 0, 0, width, height);
	} else {
		GdkRGBA top_color = RGB(64, 64, 64);
		GdkRGBA bottom_color = RGB(255, 255, 255);
		draw_outline(cr, &top_color, &bottom_color, 0, 0, width, height);
	}

	cairo_stroke (cr);
	return FALSE;
}

static void
gtk_hexbutton_pressed (GtkHexButton *hexbutton, gpointer data)
{
  GtkHexButtonPrivate *priv = gtk_hexbutton_get_instance_private (hexbutton);
  priv->down = TRUE;
}

static void
gtk_hexbutton_released (GtkHexButton *hexbutton, gpointer data)
{
	GtkHexButtonPrivate *priv = gtk_hexbutton_get_instance_private (hexbutton);
	priv->down = FALSE;
}

static void
gtk_hexbutton_class_init (GtkHexButtonClass *klass)
{
	GtkWidgetClass *widget_class;
	widget_class = (GtkWidgetClass*) klass;
	widget_class->draw = gtk_hexbutton_draw;
}

static void
gtk_hexbutton_init (GtkHexButton *hexbutton)
{
	GtkHexButtonPrivate *priv = gtk_hexbutton_get_instance_private (hexbutton);
	priv->down = FALSE;

	g_signal_connect (hexbutton, "pressed", G_CALLBACK (gtk_hexbutton_pressed), NULL);
	g_signal_connect (hexbutton, "released", G_CALLBACK (gtk_hexbutton_released), NULL);
}
