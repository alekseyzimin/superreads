/* SuperRead pipeline
 * Copyright (C) 2012  Genome group at University of Maryland.
 * 
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __DIVISOR_HPP__
#define __DIVISOR_HPP__

#include <stdint.h>
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

namespace divisor {
  inline int leading_zeroes(int x) { return __builtin_clz(x); } // CLK
  inline int leading_zeroes(unsigned int x) { return __builtin_clz(x); }
  inline int leading_zeroes(unsigned long x) { return __builtin_clzl(x); }
  inline int leading_zeroes(unsigned long long x) { return __builtin_clzll(x); }
  
  template <typename T>
  unsigned int floorLog2(T n) {
    return sizeof(T) * 8 - 1 - leading_zeroes(n);
  }
  
  template<typename T>
  unsigned int ceilLog2(T n) {
    unsigned int r = floorLog2(n);
    return n > (((T)1) << r) ? r + 1 : r;
  }
  
  template<typename T>
  T div_ceil(T a, T b) {
    T q = a / b;
    return a % b == 0 ? q : q + 1;
  }
  
  class divisor64 {
    const uint64_t d_;
#ifdef HAVE_INT128
    const uint64_t p_, m_;
#endif
    
  public:
    divisor64(uint64_t d) : 
      d_(d)
#ifdef HAVE_INT128
      , p_(ceilLog2(d_)),
      m_(div_ceil((__int128)1 << (64 + p_), (__int128)d_))
#endif
    { }
    
    inline uint64_t divide(uint64_t n) const {
#ifdef HAVE_INT128
      const __int128 n_ = (__int128)n;
      const uint64_t q = (n_ * (__int128)m_) >> 64;
      return ((n_ + q) >> p_) & (uint64_t)-1;
#else
      return n / d_;
#endif
    }

    inline uint64_t remainder(uint64_t n) const {
#ifdef HAVE_INT128
      return n - divide(n) * d_;
#else
      return n % d_;
#endif
    }
    
    inline void division(uint64_t n, uint64_t &q, uint64_t &r) const {
#ifdef HAVE_INT128
      q = divide(n);
      r = n - q * d_;
#else
      q = n / d_;
      r = n % d_;
#endif
    }

    uint64_t d() const { return d_; }
    uint64_t p() const { return p_; }
    uint64_t m() const { return m_; }
  };
}

typedef divisor::divisor64 divisor64;

inline std::ostream& operator<<(std::ostream& os, const divisor64& d) {
  return os << "d:" << d.d() << ",p:" << d.p() << ",m:" << d.m();
}
  
#endif /* __DIVISOR_HPP__ */
  