#include <pebble.h>
#include "bad.h"
  
void tick_handler(struct tm *now, TimeUnits units_changed) {
  APP_LOG(APP_LOG_LEVEL_DEBUG, "A tick happened: %02u", now->tm_sec);
  update_time(now);
}

void init(void) {
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
  show_bad();
  
}

void deinit(void) {
  hide_bad();
  tick_timer_service_unsubscribe();
}  

int main(void) {
  init();
  app_event_loop();
  deinit();

  return 0;
}
