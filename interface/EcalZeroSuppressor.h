#ifndef EcalZeroSuppressionAlgos_EcalZeroSuppressor_h
#define EcalZeroSuppressionAlgos_EcalZeroSuppressor_h

/*
 * \file EcalZeroSuppressor.h
 *
 * $Date: 2006/04/10 08:50:50 $
 * $Revision: 1.1 $
 * \author F. Cossutti
 *
*/

#include "FWCore/Framework/interface/EDProducer.h"
#include "DataFormats/Common/interface/EDProduct.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/Handle.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "CondFormats/DataRecord/interface/EcalPedestalsRcd.h"
#include "CondFormats/EcalObjects/interface/EcalPedestals.h"
#include "DataFormats/EcalDigi/interface/EcalDigiCollections.h"
#include "Geometry/CaloGeometry/interface/CaloSubdetectorGeometry.h"
#include "DataFormats/EcalDetId/interface/EcalSubdetector.h"

#include "SimCalorimetry/EcalZeroSuppressionAlgos/interface/TrivialAmplitudeAlgo.h"

#include <vector>

using namespace std;

class EcalPedestals;

template<class C> class EcalZeroSuppressor 
{
public:
  
  virtual ~EcalZeroSuppressor(){};

  // the threshold has to be expressed in number of noise sigmas for ADC counts in the highest gain

  // bool accept(const C& frame, const double & threshold);
  bool accept(const C& frame, const double & threshold);
  
  /// can be fetched every event from the EventSetup
  void setPedestals(const EcalPedestals * pedestals) {thePedestals = pedestals;} 

 private:

  const EcalPedestals * thePedestals;
 
  void findGain12Pedestal(const DetId & detId, 
                          double & pedestal, double & width);
  
  TrivialAmplitudeAlgo<C> theEnergy_;
  
};

#include "EcalZeroSuppressor.icc"
#endif