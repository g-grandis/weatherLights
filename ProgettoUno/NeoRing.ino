void weatherLight(int weather){
  int var = weather;
  var = 1;
  switch(var){
    case 1:/*   THUNDERSTORM    */
    for(int x = 0; x<20;x++)
    {
      strip.setPixelColor(x,strip.Color(45,42,123));
    }
    strip.show();
    break;
    case 2:/*   DRIZZLE    */
    for(int x = 0; x<20;x++)
    {
      strip.setPixelColor(x,strip.Color(106,166,218));
    }
    strip.show();
    break;
    case 3:/*   RAIN    */
    for(int x = 0; x<20;x++)
    {
      strip.setPixelColor(x,strip.Color(64,164,213));
    }
    strip.show();
    break;
    case 4:/*   SNOW    */
    for(int x = 0; x<20;x++)
    {
      strip.setPixelColor(x,strip.Color(255,255,255));
    }
    strip.show();
    break;
    case 5:/*   CLEAR    */
    for(int x = 0; x<20;x++)
    {
      strip.setPixelColor(x,strip.Color(230,204,29));
    }
    strip.show();
    break;
    case 6:/*   CLOUDS    */
    for(int x = 0; x<20;x++)
    {
      strip.setPixelColor(x,strip.Color(253,211,169));
    }
    strip.show();
    break;
    case 7:/*   ETC    */
    for(int x = 0; x<20;x++)
    {
      strip.setPixelColor(x,strip.Color(90,187,71));
    }
    strip.show();
    break;
  }
}
