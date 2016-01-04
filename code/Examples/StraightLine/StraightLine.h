#ifndef DNest4_StraightLine
#define DNest4_StraightLine

#include "RNG.h"
#include <valarray>
#include <ostream>

class StraightLine
{
	private:
		// The slope and intercept
		double m, b;

		// Model prediction
		std::valarray<double> mu;

	public:
		// Constructor
		StraightLine();

		// Generate the point from the prior
		void from_prior(DNest4::RNG& rng);

		// Metropolis-Hastings proposals
		double perturb(DNest4::RNG& rng);

		// Likelihood function
		double log_likelihood() const;

		// Print to stream
		void print(std::ostream& out) const;

		// Return string with column information
		std::string description() const;
};

#endif

