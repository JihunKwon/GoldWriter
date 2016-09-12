#include "BGMSCPrimaryGeneratorAction.hh"

#include "G4Proton.hh"
#include "G4Gamma.hh"
#include "G4Electron.hh"

using namespace CLHEP;

BGMSCPrimaryGeneratorAction::BGMSCPrimaryGeneratorAction()
{
//    Source = new G4ParticleGun;
//    Source->SetParticleDefinition(G4Proton::Definition());
//    Source->SetParticleEnergy(158.6*MeV);
//    Source->SetParticleMomentumDirection(G4ThreeVector(0,0,1));
//    Source->SetParticlePosition(G4ThreeVector(0,0,-2*mm));
        CircleSource = new G4SingleParticleSource;
        CircleSource->SetParticleDefinition(G4Proton::Definition());

        G4SPSEneDistribution* energy = CircleSource->GetEneDist();
        //energy->SetEnergyDisType("Gauss");
        //energy->SetBeamSigmaInE(0 *MeV);
        energy->SetMonoEnergy(10*MeV);

        G4SPSPosDistribution* position = CircleSource->GetPosDist();
        position->SetPosDisType("Plane");
        position->SetPosDisShape("Circle");
        position->SetRadius(10*nm);
        position->SetCentreCoords(G4ThreeVector(0*m, 0*m,  -1*cm));

        G4SPSAngDistribution* angular = CircleSource->GetAngDist();
        // angular->SetAngDistType("user");
        angular->SetParticleMomentumDirection(G4ThreeVector(0.0,0.0,1.0));
        angular->DefineAngRefAxes("angref1", G4ThreeVector(-1.0,0.0,0.0));
          //  angular->SetBeamSigmaInAngY(13*mrad);
          //  angular->SetBeamSigmaInAngX(13*mrad);
        CircleSource->SetNumberOfParticles(1);
}

BGMSCPrimaryGeneratorAction::~BGMSCPrimaryGeneratorAction()
{
    delete CircleSource;
  //  delete Source;
}

void BGMSCPrimaryGeneratorAction::GeneratePrimaries(G4Event* event)
{
   // CircleSource->SetNumberOfParticles(3);
   //  Source->GeneratePrimaryVertex(event);
//
        CircleSource->GeneratePrimaryVertex(event);

}
