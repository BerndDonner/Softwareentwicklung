//Das wird meine Funktion
void setup()
{
  long[] zahlen = new long[92];
  zahlen[0] = 1;
  zahlen[1] = 1;
  for(int i = 1; i < 91; i++)
  {
    zahlen[i+1] = zahlen[i] + zahlen[i-1];
  }
  println(zahlen);
}

void draw() {
}
