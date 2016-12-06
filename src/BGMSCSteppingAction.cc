#include "BGMSCSteppingAction.hh"

#include "G4Track.hh"
#include "G4TrackStatus.hh"
#include "G4CsvAnalysisManager.hh"
#include "G4ThreeVector.hh"
#include "G4VProcess.hh"
#include "G4IAEAphspWriter.hh"

void BGMSCSteppingAction::UserSteppingAction(const G4Step* aStep)
{
    if (aStep->GetPostStepPoint()->GetMaterial())
    {
        if ((aStep->GetPostStepPoint()->GetMaterial()->GetName() == "G4_Au") &&
                (aStep->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName() == "eIoni"))
            i = i+1;
    }

    G4IAEAphspWriter::GetInstance()->UserSteppingAction(aStep);

//    G4double eEnergy = aStep->GetPostStepPoint()->GetKineticEnergy()/keV;
//    G4int j;
//    G4int energy[5];

//    for (int j = 0; j < 5; j++){
//        if ((300*j < eEnergy) && (eEnergy <= 300*(j+1)))
//        {
//            energy[j] = energy[j] + 1;
//            break;
//        }
//    }
//    std::ofstream WriteEnergy("Electron_EnergyDistribution.txt");
//    for (int k = 0; k < 5; k++){
//        WriteEnergy << k << " " << energy[k] << "\n";
//    }
}
