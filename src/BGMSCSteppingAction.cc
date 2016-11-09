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
}


/*
 * /process/list
     Transportation,              Decay,               phot,              compt
               conv,     LowEnPhotoElec,       LowEnCompton,    LowEnConversion
      LowEnRayleigh,              eBrem,              eIoni,          LowEnBrem
      LowEnergyIoni,                msc,            annihil,             muIoni
            muBrems,         muPairProd,muMinusCaptureAtRest,              hIoni
           LElastic,  PionPlusInelastic, PionMinusInelastic,PiMinusAbsorptionAtRest
  KaonPlusInelastic, KaonMinusInelastic, KaonZeroLInelastic, KaonZeroSInelastic
    ProtonInelastic,AntiProtonInelastic,AntiProtonAnnihilationAtRest,   NeutronInelastic
           LFission,           LCapture,AntiNeutronInelastic,AntiNeutronAnnihilationAtRest
    LambdaInelastic,AntiLambdaInelastic,SigmaMinusInelastic,AntiSigmaMinusInelastic
 SigmaPlusInelastic,AntiSigmaPlusInelastic,   XiMinusInelastic,AntiXiMinusInelastic
    XiZeroInelastic,AntiXiZeroInelastic,OmegaMinusInelastic,AntiOmegaMinusInelastic
  DeuteronInelastic,    TritonInelastic,     AlphaInelastic
  */
