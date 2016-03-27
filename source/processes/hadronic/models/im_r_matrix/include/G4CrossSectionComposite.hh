//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
// -------------------------------------------------------------------
//      GEANT4 Class file
//
//
//      File name:     G4CrossSectionComposite
//
//      Author:        Maria Grazia Pia (MariaGrazia.Pia@genova.infn.it)
// 
//      Creation date: 15 April 1999
//
//      Modifications: 
//      
// -------------------------------------------------------------------

#ifndef G4CROSSSECTIONCOMPOSITE_HH
#define G4CROSSSECTIONCOMPOSITE_HH

#include "globals.hh"
#include "G4CrossSectionVector.hh"
#include "G4VCrossSectionSource.hh"

class G4KineticTrack;

class G4CrossSectionComposite : public G4VCrossSectionSource
{

public:

  G4CrossSectionComposite();

  virtual ~G4CrossSectionComposite();

  G4bool operator==(const G4CrossSectionComposite& right) const;
  G4bool operator!=(const G4CrossSectionComposite& right) const;

  // Cross section of composite is the sum of components cross sections
  virtual G4double CrossSection(const G4KineticTrack& trk1, const G4KineticTrack& trk2) const;
 
  virtual const G4CrossSectionVector* GetComponents() const = 0;

  virtual G4bool IsValid(G4double e) const;


protected:

private:  

  G4CrossSectionComposite(const G4CrossSectionComposite& right);

  G4CrossSectionComposite& operator=(const G4CrossSectionComposite& right);
};
  
#endif
