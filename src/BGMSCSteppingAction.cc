#include "BGMSCSteppingAction.hh"

#include "G4Track.hh"
#include "G4TrackStatus.hh"
#include "G4CsvAnalysisManager.hh"
#include "G4ThreeVector.hh"

#include "G4IAEAphspWriter.hh"

void BGMSCSteppingAction::UserSteppingAction(const G4Step* aStep)
{
    G4IAEAphspWriter::GetInstance()->UserSteppingAction(aStep);
}


