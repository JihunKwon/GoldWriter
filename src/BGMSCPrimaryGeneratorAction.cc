#include "BGMSCPrimaryGeneratorAction.hh"

#include "G4Proton.hh"
#include "G4Gamma.hh"

using namespace CLHEP;

BGMSCPrimaryGeneratorAction::BGMSCPrimaryGeneratorAction()
{
    Source = new G4ParticleGun;
    Source->SetParticleDefinition(G4Gamma::Definition());
    Source->SetParticleEnergy(60*keV);
    Source->SetParticleMomentumDirection(G4ThreeVector(0,0,1));
    Source->SetParticlePosition(G4ThreeVector(0,0,-10*mm));
}

BGMSCPrimaryGeneratorAction::~BGMSCPrimaryGeneratorAction()
{
    delete Source;
}

void BGMSCPrimaryGeneratorAction::GeneratePrimaries(G4Event* event)
{
    Source->GeneratePrimaryVertex(event);
}
