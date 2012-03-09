/*
** Copyright (C) 1998-2010 George Tzanetakis <gtzan@cs.uvic.ca>
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

#ifndef MARSYAS_LHPLUCKED_H
#define MARSYAS_LHPLUCKED_H

#include "MarSystem.h"
#include "Gain.h" 

//#include "LoopFilter.h"

#include <cstdlib>

namespace Marsyas
{
/**
	\class LHPlucked
	\ingroup Synthesis
  

   Implementation of the Karplus_Strong 1D Digital Waveguide Model. 
   http://ccrma.stanford.edu/~jos/SimpleStrings/Karplus_Strong_Algorithm.html 
   maybe: With extensions proposed by Jaffe and Smith: Blend Factor, Decay, and Stretch Factor?
   and methods used by Weiss and Sanders
*/

class marsyas_EXPORT LHPlucked: public MarSystem
{
/*  From Template
private:

	/// Add specific controls needed by this MarSystem.
	void addControls();

	/// Reads changed controls and sets up variables if necessary.
	void myUpdate(MarControlPtr sender);


	/// MarControlPtr for the gain control
	MarControlPtr ctrl_gain_EXAMPLE_;

public:
	/// LHPlucked constructor.
	LHPlucked(std::string name);

	/// LHPlucked copy constructor.
	LHPlucked(const LHPlucked& a);

	/// LHPlucked destructor.
	~LHPlucked();

	/// Implementation of the MarSystem::clone() method.
	MarSystem* clone() const;

	/// Implementation of the MarSystem::myProcess method.
	void myProcess(realvec& in, realvec& out);
*/
private: 
void addControls();
	void myUpdate(MarControlPtr sender);

  realvec delayline1_;
  realvec pickDelayLine_;
  realvec noise_;

  mrs_real delaylineSize_;
  mrs_real a_;
  mrs_real b_;
  mrs_real blend_;
  mrs_real loss_;
  mrs_real s_;
  mrs_real d_; //the delay of the all pass filter dependant on the freq
  mrs_real g_; //coefficient of all pass filter g_=-(1-d)/d+1)
  mrs_real c;//output of inverse comb filt (for pick pos)

  mrs_real noteon_;

  mrs_natural wp_;
  mrs_natural wpp_;
  
  mrs_natural rp_;
  
  mrs_natural pointer1_;
  mrs_natural pointer2_;
  mrs_natural pointer3_;
  mrs_natural picklength_;
  mrs_natural N_;
  mrs_natural p;
  MarSystem* gain_;
  realvec gout_;



public:
  LHPlucked(std::string name);
  ~LHPlucked();
  MarSystem* clone() const;  
  
  void myProcess(realvec& in, realvec& out);
};

}
//namespace Marsyas

#endif
//MARSYAS_LHPLUCKED_H

