String s = "john wayne";
String s2 = s.toUpperCase();

//Das wird meine Funktion
void setup()
{
  size(400, 200);
    
  println("Original String:  " + s); //<>//
  println("Uppercase String: " +s2);
  
}

void draw() {
  background(255);  // Setze den Hintergrund auf weiß
  fill(255, 0, 0);          // Setze die Textfarbe auf schwarz //<>//
  textSize(24);     // Setze die Textgröße
  text("Original:  " + s, 10, 50);   // <---
  text("Uppercase: " + s2, 10, 100); // <---
}

/*
Jetzt ist aber
wirklich Schluss
das nevt!
*/
//Processing: int, char, float, boolean
//C,C++:      int, char, float, bool
//Processing: String
