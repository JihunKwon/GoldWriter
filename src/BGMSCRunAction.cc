#include "BGMSCRunAction.hh"

#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4Run.hh"
#include "G4TrackingManager.hh"

#include "G4CsvAnalysisManager.hh"
#include "G4IAEAphspWriter.hh"

#include <fstream>
#include <sstream>
#include <iostream>

#define _USE_MATH_DEFINES

BGMSCRunAction::BGMSCRunAction() : G4UserRunAction()
{}

BGMSCRunAction::~BGMSCRunAction()
{}

void BGMSCRunAction::BeginOfRunAction(const G4Run* aRun)
{
    G4cout << "### Run " << aRun->GetRunID() << " start." << G4endl;
    G4IAEAphspWriter* Writer = G4IAEAphspWriter::GetInstance();
    Writer->SetZStop(10*nm);
    Writer->BeginOfRunAction(aRun);
}

void BGMSCRunAction::EndOfRunAction(const G4Run* aRun)
{
    G4IAEAphspWriter::GetInstance()->EndOfRunAction(aRun);
}
