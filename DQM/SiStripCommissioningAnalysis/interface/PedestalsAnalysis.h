#ifndef DQM_SiStripCommissioningAnalysis_PedestalsAnalysis_H
#define DQM_SiStripCommissioningAnalysis_PedestalsAnalysis_H

#include "DQM/SiStripCommissioningAnalysis/interface/CommissioningAnalysis.h"
#include <vector>

class PedestalsHistograms;
class PedestalsMonitorables;

using namespace std;

/** 
    @file DQM/SiStripCommissioningAnalysis/interface/PedestalsAnalysis.h
    @class PedestalsAnalysis
*/
class PedestalsAnalysis : public CommissioningAnalysis {
  
 public:

  PedestalsAnalysis() {;}
  virtual ~PedestalsAnalysis() {;}
  
  virtual void analysis( const PedestalsHistograms& histos, 
			 PedestalsMonitorables& monitorables );
  
};

// -----------------------------------------------------------------------------
/** 
    @file DQM/SiStripCommissioningAnalysis/interface/PedestalsAnalysis.h
    @class PedestalsHistograms 
    
    @brief Concrete implementation of CommissioningHistograms that
    contains the histograms necssary to calculate pedestals and noise.
*/
class PedestalsHistograms : public CommissioningHistograms {
  
 public:

  /** */
  PedestalsHistograms( HistoSet histos ) : CommissioningHistograms("PedestalsHistograms"), pedsHistos_(histos) {;}
  /** */
  virtual ~PedestalsHistograms() {;}
  
  // getters
  inline TH1F* sumOfSquares()  const { return pedsHistos_.sumOfSquares_; }
  inline TH1F* sumOfContents() const { return pedsHistos_.sumOfContents_; }
  inline TH1F* numOfEntries()  const { return pedsHistos_.numOfEntries_; }

 private:
  
  HistoSet pedsHistos_;
  
};

// -----------------------------------------------------------------------------
/** 
    @file DQM/SiStripCommissioningAnalysis/PedestalsAnalysis.h
    @class PedestalsMonitorables

    @brief Concrete implementation of CommissioningMonitorables that
    contains the parameters (pedetals and noise) provided by the
    histogram-based analysis.
*/
class PedestalsMonitorables : public CommissioningMonitorables {
  
 public:

  PedestalsMonitorables() : CommissioningMonitorables("PedestalsMonitorables"), rawPeds_(), rawNoise_() {;}
  virtual ~PedestalsMonitorables() {;}

  // getters
  inline const vector<float>& rawPeds() const { return rawPeds_; }
  inline const vector<float>& rawNoise() const { return rawNoise_; }
  // setters
  inline void rawPeds( vector<float>& peds ) { rawPeds_ = peds; }
  inline void rawNoise( vector<float>& noise ) { rawNoise_ = noise; }
  
 private:
  
  vector<float> rawPeds_;
  vector<float> rawNoise_;
  
};

#endif // DQM_SiStripCommissioningAnalysis_SiStripPedestalsAnalysis_H

