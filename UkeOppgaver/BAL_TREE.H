//  ***************************************************************
//  ***************************************************************
//  ***                                                         ***
//  ***                                                         ***
//  ***      NB:  VIRKER KUN NèR CONIO.H KAN BRUKES !!!!!!      ***
//  ***                                                         ***
//  ***                                                         ***
//  ***************************************************************
//  ***************************************************************


#ifndef  __BAL_TREE_H
#define  __BAL_TREE_H


#include <iostream.h>        //  cout


const char itemMIN   = char(0);
      char infoNIL[] = "Z-noden";
const int BLaCK = 0;
const int ReD   = 1;

typedef unsigned char  itemType;
typedef char* infoType;


class BalTree  {                                 //  Jfr.s.204 i lëreboka.
  private:

    int ant_rot, min_sti, max_sti, ant_sti, y;        //  NYTT: Oppgave C.
    int tot_sti;

    struct node  {
      itemType key;   infoType info;   int b;    //  NYTT:  'b'.
      node *l, *r;
      node(itemType k, infoType i, int r_b, node* ll, node* rr)
	  {  key = k;   info = i;   b = r_b;   l = ll;  r = rr;  }
    };

    node *x, *p, *g, *gg;                 //  NYTT:  Fire variable.
    node *head, *z;

    node* rotate(itemType v, node* y);
    void split(itemType v);
    void display2(node* p, int y, int x1, int x2);      //  Selvlaget
    void traverse(node* t);                      //  NYTT: Oppgave C.

  public:
    BalTree()                                    //  NYTT:  Jfr.s.226.
      {  z = new node( 0, infoNIL, BLaCK, 0, 0);
	 z->l = z;   z->r = z;
	 ant_rot = 0;                                 //  NYTT:  Oppgave C.
	 head = new node(itemMIN, 0, BLaCK, 0, z);  }
    ~BalTree()  {   /*  Slette hele treet .......  */  }
    void insert(itemType v, infoType info);
    void display(int x1, int x2);                            //  Selvlaget
    void status();                                           //  Selvlaget
};


						 //  NYTT:  Jfr.s.221.
void BalTree :: insert(itemType v, infoType info)  {
  x = head;  p = head;  g = head;
  while (x != z)  {
    gg = g;  g = p;  p = x;
    x =  (v < x->key)  ?  x->l  :  x->r;
    if (x->l->b  &&  x->r->b)  split(v);
  }
  x = new node(v, info, ReD, z, z);
  if (v < p->key)  p->l = x;   else  p->r = x;
  split(v);  head->r->b = BLaCK;
}


void BalTree :: split(itemType v)  {             //  NYTT:  Jfr.s.226..
  x->b = ReD;  x->l->b = BLaCK;  x->r->b = BLaCK;
  if (p->b)  {
     g->b = ReD;
     if (v < g->key  !=  v < p->key)  {
	++ant_rot;                                    //  NYTT:  Oppgave C.
	p = rotate(v, g);
     }
     ++ant_rot;                                       //  NYTT:  Oppgave C.
     x = rotate(v, gg);
     x->b = BLaCK;
  }
}

						 //  NYTT:  Jfr.s.225.
node* BalTree :: rotate(itemType v, node* y)  {
  node *c, *gc;
  c =  (v < y->key)  ?  y->l  :  y->r;
  if (v < c->key)
    {  gc = c->l;  c->l = gc->r;  gc->r = c;  }
  else
    {  gc = c->r;  c->r = gc->l;  gc->l = c;  }
  if (v < y->key)  y->l = gc;  else y->r = gc;
  return gc;
}


void BalTree :: display2(node* p, int y, int x1, int x2)  {
  if (p != z)  {
     int m = (x1+x2)/2;   gotoxy(m, y);
     cout << p->key << '(' << p->b << ')';
     display2(p->l, y+2, x1, m);
     display2(p->r, y+2, m, x2);
  }
}


void BalTree :: display(int x1, int x2)  {
  display2(head->r, 1, x1, x2);
}



// ***************************  OPPGAVE C:  *******************************

void BalTree :: traverse(node* t)  {      //  Jfr. s.61 i lëreboka.
  if (t != z)  {
     y++;
     traverse(t->l);
     traverse(t->r);
     y--;
  } else  {
    tot_sti += y;  ++ant_sti;
    if (y < min_sti)  min_sti = y;
    if (y > max_sti)  max_sti = y;
  }
}


void BalTree :: status()  {                      //  Selvlaget.
  cout << "\n\nAntall rotasjoner:  " << ant_rot;
  min_sti = 1000;   max_sti = 0;   tot_sti = 0;   ant_sti = 0;  y = 0;
  traverse(head->r);
  cout << "  \nKorteste sti:       " << min_sti;
  cout << "  \nLengste sti:        " << max_sti;
  cout << "  \nGj.snittlig sti:    " << tot_sti/ant_sti;
}

#endif
