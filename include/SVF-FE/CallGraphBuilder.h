//===- CallGraphBuilder.h ----------------------------------------------------------------//
//
//                     SVF: Static Value-Flow Analysis
//
// Copyright (C) <2013->  <Yulei Sui>
//

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//===----------------------------------------------------------------------===//


/*
 * CallGraphBuilder.h
 *
 *  Created on: 13Mar.,2020
 *      Author: Yulei Sui
 */

#ifndef INCLUDE_UTIL_CALLGRAPHBUILDER_H_
#define INCLUDE_UTIL_CALLGRAPHBUILDER_H_

#include "Graphs/PTACallGraph.h"
#include "Graphs/ThreadCallGraph.h"

class ICFG;

class CallGraphBuilder
{

protected:
    PTACallGraph* callgraph;
    ICFG* icfg;
public:
    CallGraphBuilder(PTACallGraph* cg, ICFG* i): callgraph(cg),icfg(i)
    {
    }

    /// Build normal callgraph
    PTACallGraph* buildCallGraph(SVFModule* svfModule);

};

class ThreadCallGraphBuilder : public CallGraphBuilder
{

public:
    ThreadCallGraphBuilder(ThreadCallGraph* cg, ICFG* i): CallGraphBuilder(cg,i)
    {
    }

    /// Build thread-aware callgraph
    PTACallGraph* buildThreadCallGraph(SVFModule* svfModule);

};




#endif /* INCLUDE_UTIL_CALLGRAPHBUILDER_H_ */