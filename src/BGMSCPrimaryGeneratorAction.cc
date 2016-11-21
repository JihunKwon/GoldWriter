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

    G4String fileName = "PSF_-199"; //Set this to your phsp file
    IAEAReader = new G4IAEAphspReader(fileName);

    G4ThreeVector isoPos(-10.0*nm, 0*nm, 0*nm);
    IAEAReader->SetIsocenterPosition(isoPos);
    IAEAReader->SetTimesRecycled(0);

//        CircleSource = new G4SingleParticleSource;
//        CircleSource->SetParticleDefinition(G4Gamma::Definition());

//        G4SPSEneDistribution* energy = CircleSource->GetEneDist();
//        //energy->SetEnergyDisType("Gauss");
//        //energy->SetBeamSigmaInE(0 *MeV);
//        energy->SetMonoEnergy(100*keV);

//        G4SPSPosDistribution* position = CircleSource->GetPosDist();
//        position->SetPosDisType("Plane");
//        position->SetPosDisShape("Circle");
//        position->SetRadius(10*nm);
//        position->SetCentreCoords(G4ThreeVector(0*m, 0*m,  -100*um));

//        G4SPSAngDistribution* angular = CircleSource->GetAngDist();
//        // angular->SetAngDistType("user");
//        angular->SetParticleMomentumDirection(G4ThreeVector(0.0,0.0,1.0));
//        angular->DefineAngRefAxes("angref1", G4ThreeVector(-1.0,0.0,0.0));
//          //  angular->SetBeamSigmaInAngY(13*mrad);
//          //  angular->SetBeamSigmaInAngX(13*mrad);
//        CircleSource->SetNumberOfParticles(1);
}

BGMSCPrimaryGeneratorAction::~BGMSCPrimaryGeneratorAction()
{
  //  delete CircleSource;
  //  delete Source;
    if (IAEAReader)
        delete IAEAReader;
}

void BGMSCPrimaryGeneratorAction::GeneratePrimaries(G4Event* event)
{
   // CircleSource->SetNumberOfParticles(3);
   //  Source->GeneratePrimaryVertex(event);
//
        //CircleSource->GeneratePrimaryVertex(event);
    IAEAReader->GeneratePrimaryVertex(event);
    std::vector<G4ThreeVector>* pos = IAEAReader->GetPositionVector();
    G4ThreeVector position = (*pos)[0];
    std::ofstream outfile;

}
