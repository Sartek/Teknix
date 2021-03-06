#include "MyContactListener.hpp"
void MyContactListener::initialize()
{
    numFootContacts = 0;
}

void MyContactListener::BeginContact(b2Contact* contact)
{
    //check if fixture A was the foot sensor
    void* fixtureUserData = contact->GetFixtureA()->GetUserData();
    if ( (intptr_t)fixtureUserData == 3 )
        numFootContacts++;
    //check if fixture B was the foot sensor
    fixtureUserData = contact->GetFixtureB()->GetUserData();
    if ( (intptr_t)fixtureUserData == 3 )
        numFootContacts++;
}

void MyContactListener::EndContact(b2Contact* contact)
{
    //check if fixture A was the foot sensor
    void* fixtureUserData = contact->GetFixtureA()->GetUserData();
    if ( (intptr_t)fixtureUserData == 3 )
        numFootContacts--;
    //check if fixture B was the foot sensor
    fixtureUserData = contact->GetFixtureB()->GetUserData();
    if ( (intptr_t)fixtureUserData == 3 )
        numFootContacts--;
}
