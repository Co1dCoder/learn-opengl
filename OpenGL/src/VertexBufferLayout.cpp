#include "VertexBufferLayout.h"


VertexBufferLayout::VertexBufferLayout()
	: m_Stride(0) {}
VertexBufferLayout::~VertexBufferLayout() {};

template<typename T> void VertexBufferLayout::Push(unsigned int count) {
	static_assert(false);
}

template<> void VertexBufferLayout::Push<float>(unsigned int count) {
	m_Elements.push_back({ count, GL_FLOAT,GL_FALSE });
	m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
}

template<> void VertexBufferLayout::Push<unsigned int>(unsigned int count) {
	m_Elements.push_back({ count, GL_UNSIGNED_INT, GL_FALSE });
	m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
}

template<> void VertexBufferLayout::Push<unsigned char>(unsigned int count) {
	m_Elements.push_back({ count,  GL_UNSIGNED_BYTE, GL_TRUE });
	m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
}
