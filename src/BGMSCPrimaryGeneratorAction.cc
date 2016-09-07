#include "BGMSCPrimaryGeneratorAction.hh"

#include "G4Proton.hh"
#include "G4Gamma.hh"
#include "G4Electron.hh"

using namespace CLHEP;

BGMSCPrimaryGeneratorAction::BGMSCPrimaryGeneratorAction()
{
    CircleSource = new G4SingleParticleSource;
    CircleSource->SetParticleDefinition(G4Proton::Definition());

    G4SPSEneDistribution* energy = CircleSource->GetEneDist();
    //energy->SetEnergyDisType("Gauss");
    //energy->SetBeamSigmaInE(0 *MeV);
    energy->SetMonoEnergy(10*MeV);

    G4SPSPosDistribution* position = CircleSource->GetPosDist();
    position->SetPosDisType("Plane");
    position->SetPosDisShape("Circle");
    position->SetRadius(10*cm);
    position->SetCentreCoords(G4ThreeVector(0*m, 0*m,  -100*cm));

    G4SPSAngDistribution* angular = CircleSource->GetAngDist();
    // angular->SetAngDistType("user");
    angular->SetParticleMomentumDirection(G4ThreeVector(0.0,0.0,1.0));
    angular->DefineAngRefAxes("angref1", G4ThreeVector(-1.0,0.0,0.0));
//    angular->SetBeamSigmaInAngY(13*mrad);
//    angular->SetBeamSigmaInAngX(13*mrad);
    CircleSource->SetNumberOfParticles(1);
}

BGMSCPrimaryGeneratorAction::~BGMSCPrimaryGeneratorAction()
{
    delete CircleSource;
}

void BGMSCPrimaryGeneratorAction::GeneratePrimaries(G4Event* event)
{
    CircleSource->GeneratePrimaryVertex(event);
}
