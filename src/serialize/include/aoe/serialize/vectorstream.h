#pragma once

#include <cstdio>
#include <cstring>
#include <iostream>
#include <streambuf>
#include <vector>

namespace aoe::serialize
{
    class vectorstream : public std::iostream
    {
        template <typename CharType>
        class vector_streambuf : public std::streambuf
        {
            typedef typename std::vector<CharType>::size_type size_type;
            size_type                                         read_pos = 0;  // buffer[read_pos] == next byte to read from buffer

        public:
            std::vector<CharType>& buffer;

            vector_streambuf(std::vector<CharType>& buffer_)
                : read_pos(0),
                  buffer(buffer_)
            {
            }

            void seekg(size_type pos)
            {
                read_pos = pos;
            }

            pos_type seekpos(pos_type pos, std::ios_base::openmode mode) override
            {
                return seekoff(pos - pos_type(off_type(0)), std::ios_base::beg, mode);
            }

            pos_type seekoff(off_type off, std::ios_base::seekdir dir, std::ios_base::openmode mode) override
            {
                (void)mode;
                // ESO_CASSERT(mode == std::ios_base::in, "vectorstream does not support std::ios_base::out");
                switch (dir)
                {
                    case std::ios_base::beg:
                        read_pos = off;
                        break;
                    case std::ios_base::cur:
                        read_pos += off;
                        break;
                    case std::ios_base::end:
                        read_pos = buffer.size() + off;
                        break;
                    default:
                        break;
                }
                return pos_type(read_pos);
            }

            // ------------------------ OUTPUT FUNCTIONS ------------------------

            int_type overflow(int_type c) override
            {
                if (c != EOF)
                    buffer.push_back(static_cast<char>(c));
                return c;
            }

            std::streamsize xsputn(const char* s, std::streamsize num) override
            {
                buffer.insert(buffer.end(), s, s + num);
                return num;
            }

            // ------------------------ INPUT FUNCTIONS ------------------------

            int_type underflow() override
            {
                if (read_pos < buffer.size())
                    return static_cast<unsigned char>(buffer[read_pos]);
                else
                    return EOF;
            }

            int_type uflow() override
            {
                if (read_pos < buffer.size())
                    return static_cast<unsigned char>(buffer[read_pos++]);
                else
                    return EOF;
            }

            int_type pbackfail(int_type c) override
            {
                // if they are trying to push back a character that they didn't read last
                // that is an error
                const unsigned long prev = read_pos - 1;
                if (c != EOF && prev < buffer.size() && c != static_cast<unsigned char>(buffer[prev]))
                {
                    return EOF;
                }

                read_pos = prev;
                return 1;
            }

            std::streamsize xsgetn(char* s, std::streamsize n) override
            {
                if (read_pos < buffer.size())
                {
                    const size_type num = std::min<size_type>(n, buffer.size() - read_pos);
                    std::memcpy(s, &buffer[read_pos], num);
                    read_pos += num;
                    return num;
                }
                return 0;
            }
        };

    public:
        explicit vectorstream(std::vector<char>& buffer)
            : std::iostream(nullptr),
              buf1(buffer),
              buf2(dummy2),
              buf3(dummy3)
        {
            rdbuf(&buf1);
        }

        explicit vectorstream(std::vector<int8_t>& buffer)
            : std::iostream(nullptr),
              buf1(dummy1),
              buf2(buffer),
              buf3(dummy3)
        {
            rdbuf(&buf2);
        }

        explicit vectorstream(std::vector<uint8_t>& buffer)
            : std::iostream(nullptr),
              buf1(dummy1),
              buf2(dummy2),
              buf3(buffer)
        {
            rdbuf(&buf3);
        }

        vectorstream(const vectorstream& ori) = delete;
        vectorstream(vectorstream&& item)     = delete;

    private:
        std::vector<char>         dummy1;
        std::vector<int8_t>       dummy2;
        std::vector<uint8_t>      dummy3;
        vector_streambuf<char>    buf1;
        vector_streambuf<int8_t>  buf2;
        vector_streambuf<uint8_t> buf3;
    };
}  // namespace aoe::serialize
