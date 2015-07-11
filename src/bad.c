#include <pebble.h>
#include "bad.h"
  
#define  MAX_CHARS 20

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GBitmap *s_res_grumpy;
static GFont s_font;
static BitmapLayer *s_bitmaplayer_1;
static TextLayer *s_textlayer_1;
static char *s_time_text;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_background_color(s_window, GColorClear);
  #ifndef PBL_SDK_3
    window_set_fullscreen(s_window, true);
  #endif
    
  s_time_text = malloc(MAX_CHARS);
  s_time_text[0] = 'A';
  s_time_text[1] = 'B';
  s_time_text[2] = '\0';
  
  s_res_grumpy = gbitmap_create_with_resource(RESOURCE_ID_GRUMPY);
  s_font = fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD);
  // s_bitmaplayer_1
  s_bitmaplayer_1 = bitmap_layer_create(GRect(0, 0, 144, 144));
  bitmap_layer_set_bitmap(s_bitmaplayer_1, s_res_grumpy);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_bitmaplayer_1);
  
  // s_textlayer_1
  s_textlayer_1 = text_layer_create(GRect(21, 146, 144, 34));
  text_layer_set_background_color(s_textlayer_1, GColorWhite);
  text_layer_set_text_color(s_textlayer_1, GColorBlack);
  text_layer_set_text(s_textlayer_1, s_time_text);
  text_layer_set_text_alignment(s_textlayer_1, GTextAlignmentCenter);
  text_layer_set_font(s_textlayer_1, s_font);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_1);
}

void update_time(struct tm *now) {
  snprintf(s_time_text, MAX_CHARS, "%02u / %02u", now->tm_hour, now->tm_min);
  layer_mark_dirty(text_layer_get_layer(s_textlayer_1));
}

static void destroy_ui(void) {
  window_destroy(s_window);
  bitmap_layer_destroy(s_bitmaplayer_1);
  text_layer_destroy(s_textlayer_1);
  gbitmap_destroy(s_res_grumpy);
  free(s_time_text);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_bad(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_bad(void) {
  window_stack_remove(s_window, true);
}
