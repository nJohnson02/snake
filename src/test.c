#include <stdio.h>
#include <gtk.h>

int main ( int argc, char *argv[], char *env[] )
{
    gtk_init(&argc, &argv);

    GdkModifierType button_state;
    gdk_window_get_pointer(NULL, NULL, NULL, &button_state);
    if(button_state & GDK_CONTROL_MASK) {
        printf("ctrl key is pressed");
    }
}