#ifndef PROJECT_KAPPA_VERTEX_BUFFER_H
#define PROJECT_KAPPA_VERTEX_BUFFER_H

class VertexBuffer {
public:
    VertexBuffer(const void* data, unsigned size);
    ~VertexBuffer();

    void bind() const;
    void unbind() const;

private:
    unsigned renderer_id_;
};

#endif //PROJECT_KAPPA_VERTEX_BUFFER_H
