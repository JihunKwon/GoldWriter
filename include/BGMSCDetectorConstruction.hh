#ifndef BGMSCDETECTORCONSTRUCTION_H
#define BGMSCDETECTORCONSTRUCTION_H

#include "G4VUserDetectorConstruction.hh"
#include "G4Material.hh"

class BGMSCDetectorMessenger;
class G4LogicalVolume;
class G4VPhysicalVolume;

using namespace CLHEP;

class BGMSCDetectorConstruction : public G4VUserDetectorConstruction
{
public:
    BGMSCDetectorConstruction();
    ~BGMSCDetectorConstruction() {}

    G4VPhysicalVolume* Construct();

 // void ConstructSDandField();
 // This method is used in multi-threaded applications to build
 // per-worker non-shared objects: SensitiveDetectors and Field managers
};

#endif

