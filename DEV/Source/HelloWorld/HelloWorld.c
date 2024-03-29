#include <furi.h>
#include <furi_hal.h>
#include <gui/gui.h>
#include <input/input.h>

// Callback function for drawing on the canvas
static void app_draw_callback(Canvas* canvas, void* ctx) {
    UNUSED(ctx);

    // Clear the canvas
    canvas_clear(canvas);

    // Draw strings on the canvas
    canvas_draw_str(canvas, 0, 6, "Hello World");
    canvas_draw_str(canvas, 0, 12, "is it...");
    canvas_draw_str(canvas, 0, 18, "Working?!");
}

// Callback function for handling input events
static void app_input_callback(InputEvent* input_event, void* ctx) {
    furi_assert(ctx);

    // Cast context to FuriMessageQueue pointer
    FuriMessageQueue* event_queue = ctx;

    // Put input event onto the event queue with indefinite waiting
    furi_message_queue_put(event_queue, input_event, FuriWaitForever);
}

// Main function for the HelloWorld application
int32_t hello_world_app(void* p) {
    UNUSED(p);

    // Allocate memory for the event queue
    FuriMessageQueue* event_queue = furi_message_queue_alloc(8, sizeof(InputEvent));

    // Configure view port
    ViewPort* view_port = view_port_alloc();
    view_port_draw_callback_set(view_port, app_draw_callback, view_port);
    view_port_input_callback_set(view_port, app_input_callback, event_queue);

    // Register view port in GUI
    Gui* gui = furi_record_open(RECORD_GUI);
    gui_add_view_port(gui, view_port, GuiLayerFullscreen);

    InputEvent event;

    bool running = true;

    // Main loop for handling input events
    while (running) {
        // Check if there's an event in the event queue
        if (furi_message_queue_get(event_queue, &event, 100) == FuriStatusOk) {
            // Process input events
            if ((event.type == InputTypePress) || (event.type == InputTypeRepeat)) {
                switch (event.key) {
                case InputKeyBack:
                    running = false; // Exit the loop
                    break;
                default:
                    break;
                }
            }
        }
    }

    // Cleanup: disable view port, remove from GUI, free memory
    view_port_enabled_set(view_port, false);
    gui_remove_view_port(gui, view_port);
    view_port_free(view_port);
    furi_message_queue_free(event_queue);
    furi_record_close(RECORD_GUI);

    return 0;
}
