#pragma once

#include "AbstractProgramBinaryImplementation.h"

namespace glow
{

class GetProgramBinaryImplementation : public AbstractProgramBinaryImplementation
{
public:
    virtual bool updateProgramLinkSource(const Program* program) const override;
    virtual ProgramBinary* getProgramBinary(const Program* program) const override;
};

} // namespace glow
