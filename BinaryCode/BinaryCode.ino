int led1 = 5;
int led2 = 6;
int led3 = 7;
int led4 = 8;
int led5 = 9;
int led6 = 10;
int led7 = 11;
int led8 = 12;
int Zahdddddl = 1;



int Hoch(int Zahl, int Hoch)
{
  int temp = Zahl;

  if (Hoch != 0)
  {
    for (int i = 1; i != Hoch; i++)
    {
      temp = temp * Zahl;
    }
  }
  else
  {
    return (1);
  }

  return temp;
}


void setup()
{


  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);


}

void loop()
{


  int ReversedZaehler = 0;
  int TempZahl = Zahl;
  bool FeldBesetzung[8] = {0, 0, 0, 0, 0, 0, 0, 0};

  while (Hoch(2, ReversedZaehler) < Zahl)
  {
    ReversedZaehler++;
  }


  while (TempZahl > 0)
  {
    if (Hoch(2, ReversedZaehler) <= TempZahl)
    {
      if (ReversedZaehler <= 8)
      {
        FeldBesetzung[ReversedZaehler ] = true;
      }


      TempZahl -= Hoch(2, ReversedZaehler);
      ReversedZaehler--;
    }
    else
    {
      if (ReversedZaehler <= 8)
      {
        FeldBesetzung[ReversedZaehler] = false;
      }


      ReversedZaehler--;

    }
  }
  while (ReversedZaehler >= 0)
  {
    FeldBesetzung[ReversedZaehler] = false;
    ReversedZaehler--;

  }

  for (int Zaehler = 8; Zaehler > 0 ; Zaehler--)
  {
    if (FeldBesetzung[Zaehler - 1] == true)
    {
      analogWrite(13 - Zaehler, HIGH);
    }

    else
    {
      analogWrite(13 - Zaehler, LOW);
    }
  }

  delay(1000);
  Zahl++;

}



