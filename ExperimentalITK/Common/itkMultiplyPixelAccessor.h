/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    $RCSfile: itkMultiplyPixelAccessor.h,v $
  Language:  C++
  Date:      $Date: 2008/10/18 00:20:04 $
  Version:   $Revision: 1.1.1.1 $

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkMultiplyPixelAccessor_h
#define __itkMultiplyPixelAccessor_h


namespace itk
{
namespace Accessor
{

/** \class MultiplyPixelAccessor
 * \brief Simulates the effect of multiplying a constant value to all pixels
 *
 * This class is intended to be used as parameter of 
 * an ImageAdaptor to make an image appear as having 
 * pixels with intensity values increased by a constant amount.
 *
 * \sa ImageAdaptor
 * \ingroup ImageAdaptors
 */

template <class TPixel>
class ITK_EXPORT MultiplyPixelAccessor
{
public:
  /** Standard class typedefs. */
  typedef   MultiplyPixelAccessor        Self;

  /** External typedef. It defines the external aspect
   * that this class will exhibit */
  typedef     TPixel      ExternalType;

  /** Internal typedef. It defines the internal real
   * representation of data */
  typedef     TPixel      InternalType;

  /** Write access to the pixel */
  inline void Set( InternalType & output, const ExternalType & input ) const
    { output = static_cast<InternalType>( input - m_Value ); }

  /** Read access to the pixel */
  inline ExternalType Get( const InternalType & input ) const
    { return static_cast<ExternalType>( input * m_Value ); }

  /** Set the value to be added to pixels */
  void SetValue( TPixel newvalue )
    { m_Value = newvalue; }

  /** Get the value to be added to pixels */
  TPixel GetValue() 
    { return m_Value; }

  /** Assignment Operator */
  Self & operator=( const Self & apa )
    { 
    this->m_Value = apa.m_Value;
    return *this; 
    }

  /** Constructors */
  MultiplyPixelAccessor():m_Value( NumericTraits<TPixel>::One ) {}
  MultiplyPixelAccessor( const Self & apa ):m_Value(apa.m_Value) {}
  
private:

  TPixel m_Value;

};

  
  
}  // end namespace Accessor
}  // end namespace itk


#endif
