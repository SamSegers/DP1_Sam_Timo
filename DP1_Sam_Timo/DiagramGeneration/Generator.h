#pragma once
#ifndef _GENERATOR_H
#define _GENERATOR_H

#include "..\circuit.h"

namespace DiagramGeneration
{
	class Generator 
	{
	public:
		void Generate(Circuit& circuit);

	protected:
		virtual void GenerateData(Circuit& circuit) = 0;
		virtual void WriteInputs() = 0;
		virtual void Show() = 0;
	};
}

#endif
