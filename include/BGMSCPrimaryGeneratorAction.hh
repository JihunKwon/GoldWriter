#ifndef BGMSCPRIMARYGENERATORACTION_H
#define BGMSCPRIMARYGENERATORACTION_H

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4SPSPosDistribution.hh"
#include "G4Types.hh"
#include "G4ParticleGun.hh"

class G4Event;

class BGMSCPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{

public:
    BGMSCPrimaryGeneratorAction();
    ~BGMSCPrimaryGeneratorAction();

    void GeneratePrimaries(G4Event* event);

private:
    G4ParticleGun* Source;
};

#endif


