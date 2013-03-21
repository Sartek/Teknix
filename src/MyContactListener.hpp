#ifndef MYCONTACTLISTENER_HPP
#define MYCONTACTLISTENER_HPP
#include <Box2D/Box2D.h>


class MyContactListener : public b2ContactListener
{
public:
    void initialize();
    void BeginContact(b2Contact* contact);
    void EndContact(b2Contact* contact);
    int numFootContacts;
};

#endif // MYCONTACTLISTENER_HPP
