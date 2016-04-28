typedef struct Nomial Nomial;

/* Single polynomial term with a pointer to the next term */
struct Nomial {
 int e;
 int c;
 Nomial* pNext;
};

Nomial* parsePolynomial(const char*);
Nomial* multiplyPolynomials(Nomial*, Nomial*);
void printPolynomial(Nomial);
