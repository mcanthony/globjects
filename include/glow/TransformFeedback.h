#pragma once

#include <glow/glow.h>

#include <glow/Object.h>
#include <glow/Program.h>
#include <glow/Array.hpp>

namespace glow
{

/** \brief The Transform Feedback class provides the interface to use transform feedback.
 * 
 * The TransformFeedback methods map directly to their OpenGL function counterparts.
 * The draw and setVaryings method additionally binds the TransformFeedback object,
 * whereas the begin, pause, resume and end methods doesn't.
 *
 * An example usage:
 * \code{.cpp}
 * Program* program = createProgramIncludingShaders();
 * TransformFeedback* transformFeeback = new TransformFeedback();
 * Buffer* buffer = new glow::Buffer(GL_ARRAY_BUFFER);
 * 
 * transformFeeback->setVaryings(program, Array<const char*>{ "vertex_out" }, GL_INTERLEAVED_ATTRIBS);
 * 
 * buffer->bindBase(GL_TRANSFORM_FEEDBACK_BUFFER, 0);
 * buffer->setData(vertexSize, nullptr, GL_DYNAMIC_DRAW);
 * 
 * program->use(); // use Program before issueing the begin method of TransformFeedback
 * 
 * transformFeeback->bind();
 * transformFeeback->begin(GL_POINTS); // record point vertices
 * 
 * // draw calls
 * 
 * transformFeeback->end(); // stop recording vertices before releasing the Program
 * transformFeeback->unbind();
 * 
 * program->release();
 * 
 * // replay recorded vertices
 * transformFeeback->draw(GL_POINTS);
 * \endcode
 * 
 * \see http://www.opengl.org/registry/specs/EXT/transform_feedback.txt
 * \see http://www.opengl.org/registry/specs/ARB/transform_feedback2.txt
 * \see http://www.opengl.org/registry/specs/ARB/transform_feedback3.txt
 */
class GLOW_API TransformFeedback : public Object
{
public:
	TransformFeedback();
	virtual ~TransformFeedback();
	
	void bind();
	void unbind();
	
	void begin(GLenum primitiveMode);
	void pause();
	void resume();
	void end();
	
	void draw(GLenum primitiveMode);
	
	void setVaryings(Program* program, GLsizei count, const char** varyingNames, GLenum bufferMode);
	void setVaryings(Program* program, const Array<const char*>& varyingNames, GLenum bufferMode);
protected:
	static GLuint genTransformFeedback();
};

} // namespace glow
