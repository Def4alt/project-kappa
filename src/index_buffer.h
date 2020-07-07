#ifndef PROJECT_KAPPA_INDEX_BUFFER_H
#define PROJECT_KAPPA_INDEX_BUFFER_H


class IndexBuffer {
public:
    IndexBuffer(const unsigned* data, unsigned count);
    ~IndexBuffer();

    void bind() const;
    void unbind() const;

    inline unsigned get_count() const { return count_; }

private:
    unsigned renderer_id_;
    unsigned count_;
};


#endif //PROJECT_KAPPA_INDEX_BUFFER_H
