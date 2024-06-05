#include <gtk/gtk.h>

static const char* file = "my_interface.glade";

void on_button_clicked(GtkButton *button, gpointer user_data) {
    GtkWindow *parent_window = GTK_WINDOW(user_data);

    GtkWidget *dialog = gtk_message_dialog_new(
        parent_window,
        GTK_DIALOG_DESTROY_WITH_PARENT,
        GTK_MESSAGE_INFO,
        GTK_BUTTONS_OK,
        "You clicked the button!"
    );

    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv); // Initialize GTK with command line arguments

    GtkBuilder* builder = gtk_builder_new();
    GError* error = NULL;

    if (gtk_builder_add_from_file(builder, file, &error) == 0) {
        g_printerr("Error loading %s: %s\n", file, error->message);
        g_clear_error(&error);
        return 1;
    }

    // GET WIDGETS
    GtkWindow *window = GTK_WINDOW(gtk_builder_get_object(builder, "Window"));
    GtkButton *button = GTK_BUTTON(gtk_builder_get_object(builder, "button"));

     //TO DO:
    //get the label object name : Label
    //change what the label says : gtk_label_set_text(GtkLabel* self,const char* str)
    

    // Error checking for widgets
    if (!window) {
        g_printerr("Error: Could not find the 'Window' widget in the Glade file.\n");
        return 1;
    }


    gtk_window_set_title(window, "GTK Example");
    gtk_window_set_default_size(window, 200, 200);

    // g_signal connects:
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    //TO DO :
    //when button is clicked call the function on_button_cliked
    //Hint : "cliked" - "destroy" and we call the window

    gtk_widget_show_all(GTK_WIDGET(window));
    gtk_main();

    return 0;
}

