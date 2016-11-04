 #include "Connector.h"

 Connector::Connector()
 {
   left = NULL;
   right = NULL;
 }
 Connector::~Connector()
 {
   delete left;
   delete right;
 }
 Connector::Connector(Shell * l, Shell * r)
 {
   left = l;
   right = r;
 }
