#include <gtk/gtk.h>


int main(int argc, char *argv[]) {

    gtk_init(&argc, &argv);

    // Create the main window
    GtkButton *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a button
    GtkButton *button = gtk_button_new_with_label("Click Me");

    // Create a check button gtk_check_button_new_with_label(char*); it is a
    // Child of the Widget class 

    // Add the button and check button to the window
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5); // Create a vertical box
    gtk_container_add(GTK_CONTAINER(window), box); // Add the box to the window
    gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 0); // Add the button to the box
//    gtk_box_pack_start(GTK_BOX(box), check_button, TRUE, TRUE, 0); // Add the check button to the box

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

