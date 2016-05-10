#include <gtk/gtk.h>

#include "hexbutton.h"
#include "hexgrid.h"

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Hello World\n");
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *hexgrid; 

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

  hexgrid = gtk_hexgrid_new (4, 50);
  gtk_container_add (GTK_CONTAINER (window), hexgrid);

  button = gtk_hexbutton_new ();
  gtk_container_add (GTK_CONTAINER (hexgrid), button);
  // gtk_layout_put(GTK_LAYOUT(hexgrid), button, 10, 10);
  gtk_widget_set_size_request (button, 50, 50);
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);

  gtk_widget_show_all (window);
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
