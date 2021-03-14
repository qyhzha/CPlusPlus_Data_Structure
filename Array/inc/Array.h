#ifndef __ARRAY_H__
#define __ARRAY_H__

#include "Object.h"
#include "Exception.h"

namespace QinLib
{

    template <typename T>
    class Array : public Object
    {
    protected:
        T *m_array;

    public:
        virtual bool set(int i, const T &e)
        {
            bool ret = ((i >= 0) && (i < length()));

            if (ret)
            {
                m_array[i] = e;
            }

            return ret;
        }

        virtual bool get(int i, T &e) const
        {
            bool ret = ((i >= 0) && (i < length()));

            if (ret)
            {
                e = m_array[i];
            }

            return ret;
        }

        T &operator[](int i)
        {
            if ((i < 0) || (i >= length()))
            {
                THROW_EXCEPTION(IndexOutOfBoundsException, "Paramer i out of bounds ...");
            }

            return m_array[i];
        }

        T operator[](int i) const
        {
            return const_cast<Array<T> &>(*this)[i];
        }

        T *array() const
        {
            return m_array;
        }

        virtual int length() const = 0;
    };

}

#endif // ARRAY_H