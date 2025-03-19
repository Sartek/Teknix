#include "MyContactListener.hpp"

//fix intptr_t if not working

void MyContactListener::initialize()
{
    numFootContacts = 0;
}

void MyContactListener::BeginContact(b2Contact* contact)
{
    //check if fixture A was the foot sensor
    b2FixtureUserData fixtureUserData = contact->GetFixtureA()->GetUserData();
    //void* fixtureUserData = contact->GetFixtureA()->GetUserData();

    if ( fixtureUserData.pointer == (uintptr_t)3 )
    //if ( (intptr_t)fixtureUserData == 3 )
        numFootContacts++;
    //check if fixture B was the foot sensor
    fixtureUserData = contact->GetFixtureB()->GetUserData();
    
    //if ( (intptr_t)fixtureUserData == 3 )
    if ( fixtureUserData.pointer == (uintptr_t)3 )
        numFootContacts++;
}

void MyContactListener::EndContact(b2Contact* contact)
{
    //check if fixture A was the foot sensor
    b2FixtureUserData fixtureUserData = contact->GetFixtureA()->GetUserData();
    //void* fixtureUserData = contact->GetFixtureA()->GetUserData();
    
    //if ( (intptr_t)fixtureUserData == 3 )
    if ( fixtureUserData.pointer == (uintptr_t)3 )
    numFootContacts--;
    //check if fixture B was the foot sensor
    fixtureUserData = contact->GetFixtureB()->GetUserData();
    //if ( (intptr_t)fixtureUserData == 3 )
    if ( fixtureUserData.pointer == (uintptr_t)3 )
        numFootContacts--;
}
