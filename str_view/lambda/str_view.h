/**
 * MIT License

 * Copyright(c) 2021 Bora Ilgar

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this softwareand associated documentation files(the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions :

 * The above copyright noticeand this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

/**
 * @brief : C++11 compatible std::string_view implementation
 *
 * @author: Bora Ilgar
 */

#ifndef STR_VIEW_H
#define STR_VIEW_H

#include <memory>
#include <ostream>
#include <stdexcept>
#include <string>

namespace lambda
{

template <typename CharT, typename Traits = std::char_traits<CharT>> struct basic_str_view
{
    using char_type = CharT;
    using trait_type = Traits;
    using size_type = size_t;

    using value_type = CharT;
    using pointer_type = CharT *;
    using const_pointer_type = const CharT *;
    using referance_type = CharT &;
    using const_referance = const CharT &;

    using iterator = const CharT *;
    using const_iterator = const CharT *;

    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    /// <summary>
    /// Constant and value. The exact meaning depends on the context.
    /// </summary>
    static constexpr size_type npos = size_type(-1);

    // --------------------------------------------------------------------------------------------------
    // Constructors
    // https://en.cppreference.com/w/cpp/string/basic_string_view/basic_string_view
    // --------------------------------------------------------------------------------------------------

    /// <summary>
    /// Constructs an empty basic_string_view. After construction, data() is equal
    /// to nullptr
    /// </summary>
    /// <returns></returns>
    constexpr basic_str_view() noexcept;

    /// <summary>
    /// Copy constructor. Constructs a view of the same content as other. After
    /// construction, data() is equal to other.data(), and size() equal to
    /// other.size()
    /// </summary>
    /// <param name="other"></param>
    /// <returns></returns>
    constexpr basic_str_view(const basic_str_view &other) noexcept = default;

    /// <summary>
    /// Constructs a  basic_string_view. After construction, data() is equal to
    /// provided CharT* and size equal to provided 'count' parameter
    /// </summary>
    /// <param name="s"></param>
    /// <param name="count"></param>
    constexpr basic_str_view(const CharT *s, size_type count);

    /// <summary>
    /// Constructs a  basic_string_view. After construction, data() is equal to
    /// provided CharT* and size equal to provided length of CharT*.
    /// </summary>
    /// <param name="s"></param>
    constexpr basic_str_view(const CharT *s);

    /// <summary>
    /// Constructs basic_str_view with std::string. After construction, data() is
    /// equal to std::string::c_str() and size equal to std::string::size()
    /// </summary>
    /// <typeparam name="Allocator"></typeparam>
    /// <param name="str"></param>
    /// <returns></returns>
    template <typename Allocator = std::allocator<CharT>>
    basic_str_view(const std::basic_string<CharT, Traits, Allocator> &str) noexcept;

    /// <summary>
    /// Assignment Operator, replaces the view with that of view.
    /// </summary>
    /// <param name="view"></param>
    /// <returns></returns>
    constexpr basic_str_view &operator=(const basic_str_view &view) noexcept = default;

    // --------------------------------------------------------------------------------------------------
    // Iterators
    // https://en.cppreference.com/w/cpp/string/basic_string_view
    // --------------------------------------------------------------------------------------------------

    /// <summary>
    /// Iterator that returns string_view first elem as CharT*
    /// </summary>
    /// <returns></returns>
    const_iterator begin() const noexcept;

    /// <summary>
    /// Iterator that returns string_view first elem as const CharT*
    /// </summary>
    /// <returns></returns>
    const_iterator cbegin() const noexcept;

    /// <summary>
    /// Iterator that returns string_view last elem as CharT*
    /// </summary>
    /// <returns> const_iterator </returns>
    const_iterator end() const noexcept;

    /// <summary>
    /// Iterator that returns string_view last elem as const CharT*
    /// </summary>
    /// <returns></returns>
    const_iterator cend() const noexcept;

    /// <summary>
    /// Iterator that returns string_view reverse first elem as CharT*
    /// </summary>
    /// <returns></returns>
    const_reverse_iterator rbegin() const noexcept;

    /// <summary>
    /// Iterator that returns string_view reverse last elem as CharT*
    /// </summary>
    /// <returns></returns>
    const_reverse_iterator rend() const noexcept;

    /// <summary>
    /// Iterator that returns string_view reverse begin elem as const CharT*
    /// </summary>
    /// <returns></returns>
    const_reverse_iterator crbegin() const noexcept;

    /// <summary>
    /// Iterator that returns string_view reverse last elem as const CharT*
    /// </summary>
    /// <returns></returns>
    const_reverse_iterator crend() const noexcept;

    // --------------------------------------------------------------------------------------------------
    // Element Access
    // --------------------------------------------------------------------------------------------------

    /// <summary>
    /// Convert basic_str_view to const CharT*
    /// </summary>
    /// <returns></returns>
    constexpr const CharT *c_str() const noexcept;

    /// <summary>
    /// Convert basic_str_view to const CharT*.
    /// </summary>
    /// <returns></returns>
    constexpr const CharT *data() const noexcept;

    /// <summary>
    /// Accesses CharT element in provided position. Returns CharT&
    /// </summary>
    /// <param name="pos"></param>
    /// <returns></returns>
    constexpr const_referance operator[](size_type pos) const noexcept;

    /// <summary>
    /// Accesses the specified character with bounds checking
    /// </summary>
    /// <param name="pos"></param>
    /// <returns></returns>
    constexpr const_referance at(size_type pos) const;

    /// <summary>
    /// Returns CharT& first element in basic_str_view
    /// </summary>
    /// <returns></returns>
    constexpr const_referance front() const;

    /// <summary>
    /// Returns CharT& last element in basic_str_view
    /// </summary>
    /// <returns></returns>
    constexpr const_referance back() const;

    // --------------------------------------------------------------------------------------------------
    // Capacity
    // --------------------------------------------------------------------------------------------------

    /// <summary>
    /// Returns number of character in basic_str_view
    /// </summary>
    /// <returns></returns>
    constexpr size_type size() const noexcept;

    /// <summary>
    /// Returns number of character in basic_str_view
    /// </summary>
    /// <returns></returns>
    constexpr size_type length() const noexcept;

    /// <summary>
    /// Returns the maximum number of characters
    /// </summary>
    /// <returns></returns>
    constexpr size_type max_size() const noexcept;

    /// <summary>
    /// Checks whether the view is empty
    /// </summary>
    /// <returns></returns>
    constexpr bool empty() const noexcept;

    // --------------------------------------------------------------------------------------------------
    // Modifiers
    // --------------------------------------------------------------------------------------------------

    /// <summary>
    /// Shrinks the view by moving its start forward
    /// </summary>
    /// <param name="n"></param>
    constexpr void remove_prefix(size_type n);
    constexpr void remove_suffix(size_type n);
    constexpr void swap(basic_str_view &v) noexcept;

    // --------------------------------------------------------------------------------------------------
    // to std::string()
    // --------------------------------------------------------------------------------------------------
    template <typename Allocator = std::allocator<CharT>>
    constexpr std::basic_string<CharT, Traits, Allocator> to_string(const Allocator &all) const;

    // --------------------------------------------------------------------------------------------------
    // Operators
    // --------------------------------------------------------------------------------------------------

    /// <summary>
    /// Copies the substring [pos, pos + rcount) to the character array pointed to by dest, where rcount is the smaller
    /// of count and size() - pos.
    /// </summary>
    /// <param name="dest"></param>
    /// <param name="count"></param>
    /// <param name="pos"></param>
    /// <returns></returns>
    size_type copy(CharT *dest, size_type count, size_type pos = 0) const;

    /// <summary>
    /// Returns a view of the substring [pos, pos + rcount), where rcount is the smaller of count and size() - pos.
    /// </summary>
    /// <param name="pos"></param>
    /// <param name="count"></param>
    /// <returns></returns>
    constexpr basic_str_view substr(size_type pos = 0, size_type count = npos) const;

    /// <summary>
    /// The length rlen of the sequences to compare is the smaller of size() and v.size(). The function compares the two
    /// views by calling traits::compare(data(), v.data(), rlen), and returns 0 based compare result.
    ///
    /// https://en.cppreference.com/w/cpp/string/basic_string_view/compare
    /// </summary>
    /// <param name="v"></param>
    /// <returns></returns>
    constexpr int compare(basic_str_view v) const noexcept;
    constexpr int compare(size_type pos1, size_type count1, basic_str_view v) const;
    constexpr int compare(size_type pos1, size_type count1, basic_str_view v, size_type pos2, size_type count2) const;
    constexpr int compare(const CharT *s) const;
    constexpr int compare(size_type pos1, size_type count1, const CharT *s) const;
    constexpr int compare(size_type pos1, size_type count1, const CharT *s, size_type count2) const;

    /// <summary>
    /// Checks if the string view begins with the given prefix, where
    ///  - the prefix is a string view.Effectively returns substr(0, sv.size()) == sv
    ///  - the prefix is a single character.Effectively returns !empty() && Traits::eq(front(), c)
    ///  - the prefix is a null - terminated character string.Effectively returns starts_with(basic_string_view(s))
    ///
    /// https://en.cppreference.com/w/cpp/string/basic_string_view/starts_with
    /// </summary>
    /// <param name="sv"></param>
    /// <returns></returns>
    constexpr bool starts_with(basic_str_view sv) const noexcept;
    constexpr bool starts_with(CharT c) const noexcept;
    constexpr bool starts_with(const CharT *s) const;

    /// <summary>
    ///  Checks if the string view ends with the given suffix, where
    ///   - the suffix is a string view.Effectively returns
    ///         size() >= sv.size() && compare(size() - sv.size(), npos, sv) == 0
    ///   - the suffix is a single character.Effectively returns !empty() && Traits::eq(back(), c)
    ///   - the suffix is a null - terminated character string.Effectively returns ends_with(basic_string_view(s))
    ///
    /// https://en.cppreference.com/w/cpp/string/basic_string_view/ends_with
    /// </summary>
    /// <param name="sv"></param>
    /// <returns></returns>
    constexpr bool ends_with(basic_str_view sv) const noexcept;
    constexpr bool ends_with(CharT c) const noexcept;
    constexpr bool ends_with(const CharT *s) const;

    constexpr bool contains(basic_str_view sv) const noexcept;
    constexpr bool contains(CharT c) const noexcept;
    constexpr bool contains(const CharT *s) const;

    constexpr size_type find(basic_str_view v, size_type pos = 0) const noexcept;
    constexpr size_type find(CharT ch, size_type pos = 0) const noexcept;
    constexpr size_type find(const CharT *s, size_type pos, size_type count) const;
    constexpr size_type find(const CharT *s, size_type pos = 0) const;

    constexpr size_type rfind(basic_str_view v, size_type pos = npos) const noexcept;
    constexpr size_type rfind(CharT c, size_type pos = npos) const noexcept;
    constexpr size_type rfind(const CharT *s, size_type pos, size_type count) const;
    constexpr size_type rfind(const CharT *s, size_type pos = npos) const;

    /// <summary>
    /// Finds the first occurrence of any of the characters of v in this view, starting at position pos.
    /// Equivalent to find_first_of(basic_string_view(std::addressof(c), 1), pos).
    /// Equivalent to find_first_of(basic_string_view(s, count), pos).
    /// Equivalent to find_first_of(basic_string_view(s), pos).
    ///
    /// https://en.cppreference.com/w/cpp/string/basic_string_view/find_first_of
    /// </summary>
    /// <typeparam name="CharT"></typeparam>
    /// <typeparam name="Traits"></typeparam>
    /// <param name="v"></param>
    /// <param name="pos"></param>
    /// <returns></returns>
    constexpr size_type find_first_of(basic_str_view v, size_type pos = 0) const noexcept;
    constexpr size_type find_first_of(CharT c, size_type pos = 0) const noexcept;
    constexpr size_type find_first_of(const CharT *s, size_type pos, size_type count) const;
    constexpr size_type find_first_of(const CharT *s, size_type pos = 0) const;

    /// <summary>
    /// Finds the last occurence of any of the characters of v in this view, ending at position pos.
    /// Equivalent to find_last_of(basic_string_view(std::addressof(c), 1), pos).
    /// Equivalent to find_last_of(basic_string_view(s, count), pos).
    /// Equivalent to find_last_of(basic_string_view(s), pos).
    ///
    /// https://en.cppreference.com/w/cpp/string/basic_string_view/find_last_of
    /// </summary>
    /// <param name="v"></param>
    /// <param name="pos"></param>
    /// <returns></returns>
    constexpr size_type find_last_of(basic_str_view v, size_type pos = npos) const noexcept;
    constexpr size_type find_last_of(CharT c, size_type pos = npos) const noexcept;
    constexpr size_type find_last_of(const CharT *s, size_type pos, size_type count) const;
    constexpr size_type find_last_of(const CharT *s, size_type pos = npos) const;

    /// <summary>
    /// Finds the first character not equal to any of the characters of v in this view, starting at position pos.
    /// Equivalent to find_first_not_of(basic_string_view(std::addressof(c), 1), pos).
    /// Equivalent to find_first_not_of(basic_string_view(s, count), pos).
    /// Equivalent to find_first_not_of(basic_string_view(s), pos).
    ///
    /// https://en.cppreference.com/w/cpp/string/basic_string_view/find_first_not_of
    /// </summary>
    /// <param name="v"></param>
    /// <param name="pos"></param>
    /// <returns></returns>
    constexpr size_type find_first_not_of(basic_str_view v, size_type pos = 0) const noexcept;
    constexpr size_type find_first_not_of(CharT c, size_type pos = 0) const noexcept;
    constexpr size_type find_first_not_of(const CharT *s, size_type pos, size_type count) const;
    constexpr size_type find_first_not_of(const CharT *s, size_type pos = 0) const;

    /// <summary>
    /// Finds the last character not equal to any of the characters of v in this view, starting at position pos.
    /// Equivalent to find_last_not_of(basic_string_view(std::addressof(c), 1), pos).
    /// Equivalent to find_last_not_of(basic_string_view(s, count), pos).
    /// Equivalent to find_last_not_of(basic_string_view(s), pos).
    ///
    /// https://en.cppreference.com/w/cpp/string/basic_string_view/find_last_not_of
    /// </summary>
    /// <param name="v"></param>
    /// <param name="pos"></param>
    /// <returns></returns>
    constexpr size_type find_last_not_of(basic_str_view v, size_type pos = npos) const noexcept;
    constexpr size_type find_last_not_of(CharT c, size_type pos = npos) const noexcept;
    constexpr size_type find_last_not_of(const CharT *s, size_type pos, size_type count) const;
    constexpr size_type find_last_not_of(const CharT *s, size_type pos = npos) const;
#if 0
        template <> struct hash<std::string_view>;
        template <> struct hash<std::wstring_view>;
        template <> struct hash<std::u8string_view>;
        template <> struct hash<std::u16string_view>;
        template <> struct hash<std::u32string_view>;
#endif
  private:
    const CharT *m_str;
    size_type m_length;
};

// ---------------------------------------------------------------------------------------------------------------------

using str_view = basic_str_view<char>;
using wstr_view = basic_str_view<wchar_t>;
using u16str_view = basic_str_view<char16_t>;
using u32str_view = basic_str_view<char32_t>;

template <typename CharT, typename Traits>
inline constexpr basic_str_view<CharT, Traits>::basic_str_view() noexcept : m_str(nullptr), m_length(0)
{
}

template <typename CharT, typename Traits>
inline constexpr basic_str_view<CharT, Traits>::basic_str_view(const CharT *s, size_type count)
    : m_str(s), m_length(count)
{
}

template <typename CharT, typename Traits>
inline constexpr basic_str_view<CharT, Traits>::basic_str_view(const CharT *s)
    : m_str(s), m_length(trait_type::length(s))
{
}

template <typename CharT, typename Traits>
template <typename Allocator>
inline basic_str_view<CharT, Traits>::basic_str_view(const std::basic_string<CharT, Traits, Allocator> &str) noexcept
    : m_str(str.c_str()), m_length(str.size())
{
}

// -----------------------------------------------------------------------------------------------------------------------

template <typename CharT, typename Traits>
inline typename basic_str_view<CharT, Traits>::const_iterator basic_str_view<CharT, Traits>::begin() const noexcept
{
    return m_str;
}

template <typename CharT, typename Traits>
inline typename basic_str_view<CharT, Traits>::const_iterator basic_str_view<CharT, Traits>::cbegin() const noexcept
{
    return m_str;
}

template <typename CharT, typename Traits>
inline typename basic_str_view<CharT, Traits>::const_iterator basic_str_view<CharT, Traits>::end() const noexcept
{
    return m_str + m_length;
}

template <typename CharT, typename Traits>
inline typename basic_str_view<CharT, Traits>::const_iterator basic_str_view<CharT, Traits>::cend() const noexcept
{
    return m_str + m_length;
}

template <typename CharT, typename Traits>
inline typename basic_str_view<CharT, Traits>::const_reverse_iterator basic_str_view<CharT, Traits>::rbegin()
    const noexcept
{
    return m_str + m_length;
}

template <typename CharT, typename Traits>
inline typename basic_str_view<CharT, Traits>::const_reverse_iterator basic_str_view<CharT, Traits>::rend()
    const noexcept
{
    return m_str;
}

template <typename CharT, typename Traits>
inline typename basic_str_view<CharT, Traits>::const_reverse_iterator basic_str_view<CharT, Traits>::crbegin()
    const noexcept
{
    return m_str + m_length;
}

template <typename CharT, typename Traits>
inline typename basic_str_view<CharT, Traits>::const_reverse_iterator basic_str_view<CharT, Traits>::crend()
    const noexcept
{
    return m_str;
}

// -----------------------------------------------------------------------------------------------------------------------

template <typename CharT, typename Traits>
inline constexpr const CharT *basic_str_view<CharT, Traits>::c_str() const noexcept
{
    return m_str;
}

template <typename CharT, typename Traits>
inline constexpr const CharT *basic_str_view<CharT, Traits>::data() const noexcept
{
    return m_str;
}

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::const_referance basic_str_view<CharT, Traits>::operator[](
    size_type pos) const noexcept
{
    return m_str[pos];
}

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::const_referance basic_str_view<CharT, Traits>::at(
    size_type pos) const
{
    return pos < m_length ? m_str[pos] : throw std::out_of_range("Index out of range std::string_view::at");
}

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::const_referance basic_str_view<CharT, Traits>::front() const
{
    return *m_str;
}

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::const_referance basic_str_view<CharT, Traits>::back() const
{
    return *m_str[m_length - 1];
}

// -----------------------------------------------------------------------------------------------------------------------

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::size() const noexcept
{
    return m_length;
}

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::length()
    const noexcept
{
    return m_length;
}

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::max_size()
    const noexcept
{
    return npos - 1;
}

template <typename CharT, typename Traits> inline constexpr bool basic_str_view<CharT, Traits>::empty() const noexcept
{
    return m_length == 0;
}

// -----------------------------------------------------------------------------------------------------------------------

template <typename CharT, typename Traits>
inline constexpr void basic_str_view<CharT, Traits>::remove_prefix(size_type n)
{
}
#if 0

template <typename CharT, typename Traits>
inline constexpr void basic_str_view<CharT, Traits>::remove_suffix(size_type n)
{
}

template <typename CharT, typename Traits>
inline constexpr void basic_str_view<CharT, Traits>::swap(basic_str_view &v) noexcept
{
}

#endif

// -----------------------------------------------------------------------------------------------------------------------

template <typename CharT, typename Traits>
template <typename Allocator>
inline constexpr std::basic_string<CharT, Traits, Allocator> basic_str_view<CharT, Traits>::to_string(
    const Allocator &all) const
{
    return std::basic_string<CharT, Traits, Allocator>(m_str, m_length, all);
}

template <typename CharT, typename Traits>
typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::copy(CharT *dest, size_type count,
                                                                                      size_type pos) const
{
    if (pos >= m_length)
    {
        throw std::out_of_range("Index out of range in std::string_view::copy");
    }

    const size_type rc = std::min(m_length - pos, count + 1);
    std::copy(m_str + pos, m_str + pos + rc, dest);
    return rc;
}

template <typename CharT, typename Traits>
inline constexpr basic_str_view<CharT, Traits> basic_str_view<CharT, Traits>::substr(size_type pos,
                                                                                     size_type count) const
{
    const size_type max_length = pos > m_length ? 0 : m_length - pos;

    if (pos > m_length)
    {
        throw std::out_of_range("Index out of range in basic_string_view::substr");
    }

    return basic_str_view(m_str + pos, std::min(count, max_length));
}

// -----------------------------------------------------------------------------------------------------------------------

template <typename CharT, typename Traits>
inline constexpr int basic_str_view<CharT, Traits>::compare(basic_str_view v) const noexcept
{
    const size_type rlen = (m_length, v.length());
    const int compare = trait_type::compare(m_str, v.m_str, rlen);

    return (compare ? compare : (m_length < v.m_length ? -1 : (m_length > v.m_length ? 1 : 0)));
}

template <typename CharT, typename Traits>
inline constexpr int basic_str_view<CharT, Traits>::compare(size_type pos1, size_type count1, basic_str_view v) const
{
    return substr(pos1, count1).compare(v);
}

template <typename CharT, typename Traits>
inline constexpr int basic_str_view<CharT, Traits>::compare(size_type pos1, size_type count1, basic_str_view v,
                                                            size_type pos2, size_type count2) const
{
    return substr(pos1, count1).compare(v.substr(pos2, count2));
}

template <typename CharT, typename Traits>
inline constexpr int basic_str_view<CharT, Traits>::compare(const CharT *s) const
{
    return compare(basic_str_view<CharT, Traits>(s));
}

template <typename CharT, typename Traits>
inline constexpr int basic_str_view<CharT, Traits>::compare(size_type pos1, size_type count1, const CharT *s) const
{
    return substr(pos1, count1).compare(basic_str_view<CharT, Traits>(s));
}

template <typename CharT, typename Traits>
inline constexpr int basic_str_view<CharT, Traits>::compare(size_type pos1, size_type count1, const CharT *s,
                                                            size_type count2) const
{
    return substr(pos1, count1).compare(basic_str_view<CharT, Traits>(s, count2));
}

// starts with
template <typename CharT, typename Traits>
inline constexpr bool basic_str_view<CharT, Traits>::starts_with(basic_str_view sv) const noexcept
{
    return compare(0, sv.size(), sv) == 0;
}

template <typename CharT, typename Traits>
inline constexpr bool basic_str_view<CharT, Traits>::starts_with(CharT c) const noexcept
{
    return c == m_str;
}

template <typename CharT, typename Traits>
inline constexpr bool basic_str_view<CharT, Traits>::starts_with(const CharT *s) const
{
    return compare(0, trait_type::length(s), basic_str_view<CharT, Traits>(s)) == 0;
}

// ends with
template <typename CharT, typename Traits>
inline constexpr bool basic_str_view<CharT, Traits>::ends_with(basic_str_view sv) const noexcept
{
    return compare(m_length - sv.length(), sv.length(), sv);
}

template <typename CharT, typename Traits>
inline constexpr bool basic_str_view<CharT, Traits>::ends_with(CharT c) const noexcept
{
    return c == *m_str[m_length - 1];
}

template <typename CharT, typename Traits>
inline constexpr bool basic_str_view<CharT, Traits>::ends_with(const CharT *s) const
{
    return compare(m_length - trait_type::length(s), trait_type::length(s), basic_str_view<CharT, Traits>(s));
}

// contains
template <typename CharT, typename Traits>
inline constexpr bool basic_str_view<CharT, Traits>::contains(basic_str_view sv) const noexcept
{
    return find(sv) != npos;
}

template <typename CharT, typename Traits>
inline constexpr bool basic_str_view<CharT, Traits>::contains(CharT c) const noexcept
{
    return find(c) != npos;
}

template <typename CharT, typename Traits>
inline constexpr bool basic_str_view<CharT, Traits>::contains(const CharT *s) const
{
    return find(basic_str_view<CharT, Traits>(s)) != npos;
}

// ------------------------------------------------------------------------------------------------------------------

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::find(
    basic_str_view v, size_type pos) const noexcept
{
    if (pos > m_length || pos + v.size() > m_length)
    {
        return npos;
    }
    const auto increments = m_length - v.size() - pos;
    for (auto i = 0u; i <= increments; ++i)
    {
        const auto j = i + pos;
        if (substr(j, v.size()) == v)
        {
            return j;
        }
    }

    return npos;
}

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::find(
    CharT ch, size_type pos) const noexcept
{
    if (pos > m_length)
    {
        return npos;
    }
    const auto increments = m_length - 1 - pos;
    for (auto i = 0u; i <= increments; ++i)
    {
        const auto j = i + pos;
        if (m_str[j] == ch)
        {
            return j;
        }
    }

    return npos;
}

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::find(
    const CharT *s, size_type pos, size_type len) const
{
    return find(basic_str_view<CharT, Traits>(s, len), pos);
}

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::find(
    const CharT *s, size_type pos) const
{
    return find(basic_str_view<CharT, Traits>(s), pos);
}

// ------------------------------------------------------------------------------------------------------------------

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::rfind(
    basic_str_view v, size_type pos) const noexcept
{
    if (empty())
    {
        return v.empty() ? 0u : npos;
    }
    if (v.empty())
    {
        return std::min(size() - 1, pos);
    }
    if (v.size() > size())
    {
        return npos;
    }

    auto i = std::min(pos, (size() - v.size()));
    while (i != npos)
    {
        if (substr(i, v.size()) == v)
        {
            return i;
        }
        --i;
    }

    return npos;
}

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::rfind(
    CharT c, size_type pos) const noexcept
{
    return rfind(basic_str_view<CharT, Traits>(&c, 1), pos);
}

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::rfind(
    const CharT *s, size_type pos, size_type len) const
{
    return rfind(basic_str_view<CharT, Traits>(s, len), pos);
}

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::rfind(
    const CharT *s, size_type pos) const
{
    return rfind(basic_str_view<CharT, Traits>(s), pos);
}

template <typename CharT, typename Traits>
inline std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os,
                                                     basic_str_view<CharT, Traits> v)
{
    os.write(v.data(), v.size());
    return os;
}

// ------------------------------------------------------------------------------------------------------------------

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::find_first_of(
    basic_str_view v, size_type pos) const noexcept
{
    for (size_type idx = pos; idx < m_length; ++idx)
    {
        for (size_type j = 0; j < v.size(); ++j)
        {
            if (m_str[j] == v[idx])
            {
                return j;
            }
        }
    }
    return npos;
}

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::find_first_of(
    CharT c, size_type pos) const noexcept
{
    return find_first_of(basic_str_view<CharT, Traits>(&c, 1), pos);
}

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::find_first_of(
    const CharT *s, size_type pos, size_type count) const
{
    return find_first_of(basic_str_view<CharT, Traits>(s, count), pos);
}

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::find_first_of(
    const CharT *s, size_type pos) const
{
    return find_first_of(basic_str_view<CharT, Traits>(s), pos);
}

// -------------------------------------------------------------------------------------------------------------

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::find_last_of(
    basic_str_view v, size_type pos /*where to end*/) const noexcept
{
    if (v.empty())
        return npos;

    const auto len = std::min(m_length - 1, pos);
    for (size_type idx{0}; idx <= len; ++idx)
    {
        const auto = len - idx;
        for (size_type jdx{0}; jdx <= len; ++jdx)
        {
            if (m_str[idx] == v[jdx])
            {
                return jdx;
            }
        }
    }
    return npos;
}

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::find_last_of(
    CharT c, size_type pos) const noexcept
{
    return find_last_of(basic_str_view<CharT, Traits>(&c, 1), pos);
}

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::find_last_of(
    const CharT *s, size_type pos, size_type count) const
{
    return find_last_of(basic_str_view<CharT, Traits>(s, count), pos);
}

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::find_last_of(
    const CharT *s, size_type pos) const
{
    return find_last_of(basic_str_view<CharT, Traits>(s), pos);
}

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::find_first_not_of(
    basic_str_view v, size_type pos) const noexcept
{
    for (size_type idx = pos; idx < m_length; ++idx)
    {
        for (size_type j = 0; j < v.size(); ++j)
        {
            if (m_str[j] != v[idx])
            {
                return j;
            }
        }
    }
    return npos;
}

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::find_first_not_of(
    CharT c, size_type pos) const noexcept
{
    return find_first_not_of(basic_str_view<CharT, Traits>(&c, 1), pos);
}

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::find_first_not_of(
    const CharT *s, size_type pos, size_type count) const
{
    return find_first_not_of(basic_str_view<CharT, Traits>(s, count), pos);
}

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::find_first_not_of(
    const CharT *s, size_type pos) const
{
    return find_first_not_of(basic_str_view<CharT, Traits>(s), pos);
}

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::find_last_not_of(
    basic_str_view v, size_type pos) const noexcept
{
    if (v.empty())
        return npos;

    const auto len = std::min(m_length - 1, pos);
    for (size_type idx{0}; idx <= len; ++idx)
    {
        const auto = len - idx;
        for (size_type jdx{0}; jdx <= len; ++jdx)
        {
            if (m_str[idx] != v[jdx])
            {
                return jdx;
            }
        }
    }
    return npos;
}

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::find_last_not_of(
    CharT c, size_type pos) const noexcept
{
    return find_last_not_of(basic_str_view<CharT, Traits>(&c, 1), pos);
}

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::find_last_not_of(
    const CharT *s, size_type pos, size_type count) const
{
    return find_last_not_of(basic_str_view<CharT, Traits>(s, count), pos);
}

template <typename CharT, typename Traits>
inline constexpr typename basic_str_view<CharT, Traits>::size_type basic_str_view<CharT, Traits>::find_last_not_of(
    const CharT *s, size_type pos) const
{
    return find_last_not_of(basic_str_view<CharT, Traits>(s), pos);
}

template <typename CharT, typename Traits>
inline constexpr bool operator==(basic_str_view<CharT, Traits> lhs, basic_str_view<CharT, Traits> rhs) noexcept
{
    return rhs.compare(rhs) == 0;
}

template <typename CharT, typename Traits>
constexpr bool operator==(basic_str_view<CharT, Traits> lhs, const CharT *rhs) noexcept
{
    return lhs == basic_str_view<CharT, Traits>(rhs);
}

template <typename CharT, typename Traits>
constexpr bool operator==(const CharT *rhs, basic_str_view<CharT, Traits> lhs) noexcept
{
    return basic_str_view<CharT, Traits>(rhs) == lhs;
}

template <typename CharT, typename Traits, typename Allocator>
constexpr bool operator==(basic_str_view<CharT, Traits> lhs,
                          const std::basic_string<CharT, Traits, Allocator> &std_str) noexcept
{
    return lhs == basic_str_view<CharT, Traits>(std_str);
}

template <typename CharT, typename Traits, typename Allocator>
constexpr bool operator==(const std::basic_string<CharT, Traits, Allocator> &std_str,
                          basic_str_view<CharT, Traits> lhs) noexcept
{
    return basic_str_view<CharT, Traits>(std_str) == lhs;
}

//
template <typename CharT, typename Traits>
inline constexpr bool operator!=(basic_str_view<CharT, Traits> lhs, basic_str_view<CharT, Traits> rhs) noexcept
{
    return rhs.compare(rhs) != 0;
}

template <typename CharT, typename Traits>
constexpr bool operator!=(basic_str_view<CharT, Traits> lhs, const CharT *rhs) noexcept
{
    return lhs != basic_str_view<CharT, Traits>(rhs);
}

template <typename CharT, typename Traits>
constexpr bool operator!=(const CharT *rhs, basic_str_view<CharT, Traits> lhs) noexcept
{
    return basic_str_view<CharT, Traits>(rhs) != lhs;
}

template <typename CharT, typename Traits, typename Allocator>
constexpr bool operator!=(basic_str_view<CharT, Traits> lhs,
                          const std::basic_string<CharT, Traits, Allocator> &std_str) noexcept
{
    return lhs != basic_str_view<CharT, Traits>(std_str);
}

template <typename CharT, typename Traits, typename Allocator>
constexpr bool operator!=(const std::basic_string<CharT, Traits, Allocator> &std_str,
                          basic_str_view<CharT, Traits> lhs) noexcept
{
    return basic_str_view<CharT, Traits>(std_str) == lhs;
}

//
template <typename CharT, typename Traits>
inline constexpr bool operator<(basic_str_view<CharT, Traits> lhs, basic_str_view<CharT, Traits> rhs) noexcept
{
    return rhs.compare(rhs) < 0;
}

template <typename CharT, typename Traits>
constexpr bool operator<(basic_str_view<CharT, Traits> lhs, const CharT *rhs) noexcept
{
    return lhs < basic_str_view<CharT, Traits>(rhs);
}

template <typename CharT, typename Traits>
constexpr bool operator<(const CharT *rhs, basic_str_view<CharT, Traits> lhs) noexcept
{
    return basic_str_view<CharT, Traits>(rhs) < lhs;
}

template <typename CharT, typename Traits, typename Allocator>
constexpr bool operator<(basic_str_view<CharT, Traits> lhs,
                         const std::basic_string<CharT, Traits, Allocator> &std_str) noexcept
{
    return lhs < basic_str_view<CharT, Traits>(std_str);
}

template <typename CharT, typename Traits, typename Allocator>
constexpr bool operator<(const std::basic_string<CharT, Traits, Allocator> &std_str,
                         basic_str_view<CharT, Traits> lhs) noexcept
{
    return basic_str_view<CharT, Traits>(std_str) == lhs;
}

template <typename CharT, typename Traits>
inline constexpr bool operator<=(basic_str_view<CharT, Traits> lhs, basic_str_view<CharT, Traits> rhs) noexcept
{
    return rhs.compare(rhs) <= 0;
}

template <typename CharT, typename Traits>
constexpr bool operator<=(basic_str_view<CharT, Traits> lhs, const CharT *rhs) noexcept
{
    return lhs <= basic_str_view<CharT, Traits>(rhs);
}

template <typename CharT, typename Traits>
constexpr bool operator<=(const CharT *rhs, basic_str_view<CharT, Traits> lhs) noexcept
{
    return basic_str_view<CharT, Traits>(rhs) < lhs;
}

template <typename CharT, typename Traits, typename Allocator>
constexpr bool operator<=(basic_str_view<CharT, Traits> lhs,
                          const std::basic_string<CharT, Traits, Allocator> &std_str) noexcept
{
    return lhs < basic_str_view<CharT, Traits>(std_str);
}

template <typename CharT, typename Traits, typename Allocator>
constexpr bool operator<=(const std::basic_string<CharT, Traits, Allocator> &std_str,
                          basic_str_view<CharT, Traits> lhs) noexcept
{
    return basic_str_view<CharT, Traits>(std_str) == lhs;
}
//

template <typename CharT, typename Traits>
inline constexpr bool operator>(basic_str_view<CharT, Traits> lhs, basic_str_view<CharT, Traits> rhs) noexcept
{
    return rhs.compare(rhs) > 0;
}

template <typename CharT, typename Traits>
constexpr bool operator>(basic_str_view<CharT, Traits> lhs, const CharT *rhs) noexcept
{
    return lhs > basic_str_view<CharT, Traits>(rhs);
}

template <typename CharT, typename Traits>
constexpr bool operator>(const CharT *rhs, basic_str_view<CharT, Traits> lhs) noexcept
{
    return basic_str_view<CharT, Traits>(rhs) < lhs;
}

template <typename CharT, typename Traits, typename Allocator>
constexpr bool operator>(basic_str_view<CharT, Traits> lhs,
                         const std::basic_string<CharT, Traits, Allocator> &std_str) noexcept
{
    return lhs < basic_str_view<CharT, Traits>(std_str);
}

template <typename CharT, typename Traits, typename Allocator>
constexpr bool operator>(const std::basic_string<CharT, Traits, Allocator> &std_str,
                         basic_str_view<CharT, Traits> lhs) noexcept
{
    return basic_str_view<CharT, Traits>(std_str) == lhs;
}

//
template <typename CharT, typename Traits>
inline constexpr bool operator>=(basic_str_view<CharT, Traits> lhs, basic_str_view<CharT, Traits> rhs) noexcept
{
    return rhs.compare(rhs) >= 0;
}

template <typename CharT, typename Traits>
constexpr bool operator>=(basic_str_view<CharT, Traits> lhs, const CharT *rhs) noexcept
{
    return lhs >= basic_str_view<CharT, Traits>(rhs);
}

template <typename CharT, typename Traits>
constexpr bool operator>=(const CharT *rhs, basic_str_view<CharT, Traits> lhs) noexcept
{
    return basic_str_view<CharT, Traits>(rhs) < lhs;
}

template <typename CharT, typename Traits, typename Allocator>
constexpr bool operator>=(basic_str_view<CharT, Traits> lhs,
                          const std::basic_string<CharT, Traits, Allocator> &std_str) noexcept
{
    return lhs >= basic_str_view<CharT, Traits>(std_str);
}

template <typename CharT, typename Traits, typename Allocator>
constexpr bool operator>=(const std::basic_string<CharT, Traits, Allocator> &std_str,
                          basic_str_view<CharT, Traits> lhs) noexcept
{
    return basic_str_view<CharT, Traits>(std_str) == lhs;
}

constexpr str_view operator"" _sv(const char *str, std::size_t len) noexcept
{
    return str_view(str, len);
}

constexpr u16str_view operator"" _sv(const char16_t *str, std::size_t len) noexcept
{
    return u16str_view(str, len);
}

constexpr u32str_view operator"" _sv(const char32_t *str, std::size_t len) noexcept
{
    return u32str_view(str, len);
}

constexpr wstr_view operator"" _sv(const wchar_t *str, std::size_t len) noexcept
{
    return wstr_view(str, len);
}

} // namespace lambda
#endif
