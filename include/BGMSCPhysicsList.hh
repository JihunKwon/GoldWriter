#ifndef BGMSCPHYSICSLIST_H
#define BGMSCPHYSICSLIST_H

#include "G4VModularPhysicsList.hh"
#include "globals.hh"

class BGMSCPhysicsList: public G4VModularPhysicsList
{
public:

  BGMSCPhysicsList();
  virtual ~BGMSCPhysicsList();

  void SetCuts();
  void ConstructProcess();

private:
  G4double cutForGamma;
  G4double cutForElectron;
  G4double cutForPositron;
};

#endif
