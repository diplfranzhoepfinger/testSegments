/*******************************************************************************
 * Copyright (c) 2008 - 2015 nxtControl GmbH, ACIN, fortiss GmbH
 *               2023 Martin Erich Jobst
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *    Stanislav Meduna, Alois Zoitl
 *      - initial implementation and rework communication infrastructure
 *    Martin Jobst
 *      - add string functions accepting a size parameter
 *******************************************************************************/
#ifndef _CStringDictionary_H_
#define _CStringDictionary_H_

#include "singlet.h"
#include <cstdint>
#include <cstddef>

/**\ingroup CORE\brief Manages a dictionary of strings that can be referenced by ids
 *
 * Manages a dictionary of strings that can be referenced by ids
 */
// cppcheck-suppress noConstructor
class CStringDictionary{
  DECLARE_SINGLETON(CStringDictionary)
public:
  typedef uint32_t TForteUInt32; /**< 32 bit unsigned */
  typedef TForteUInt32 TStringId;

  //!\brief Invalid string id
  static const TStringId scm_nInvalidStringId = 0xffffffff;


  /*!\brief Get a string from the dictionary
   *
   * \param pa_nId String id
   * \return the found string or 0 if not found
   */
  const char *get(TStringId pa_nId);

  /*!\brief Insert a string into the dictionary
   *
   * \param pa_sStr String to be inserted
   * \return id of the inserted string (or the existing one if the dictionary already has it)
   */
  TStringId insert(const char *paStr);

  /*!\brief Insert a string into the dictionary
   *
   * \param paStr String to be searched for (need not be '\0' terminated)
   * \param paStrSize Size of the string (excluding any terminating '\0' character)
   * \return id of the inserted string (or the existing one if the dictionary already has it)
   */
  TStringId insert(const char *paStr, size_t paStrSize);

  /*!\brief Retrieve the Id of a given string if it is already in the dictionary
   *
   * \param pa_sStr String to be searched for
   * \return id of the string (or scm_nInvalidStringId if it is not in the dictionary)
   */
  TStringId getId(const char *pa_sStr) const{
    unsigned int nIdx;
    return findEntry(pa_sStr, nIdx);
  }

  /*!\brief Retrieve the Id of a given string if it is already in the dictionary
   *
   * \param paStr String to be searched for (need not be '\0' terminated)
   * \param paStrSize Size of the string (excluding any terminating '\0' character)
   * \return id of the string (or scm_nInvalidStringId if it is not in the dictionary)
   */
  TStringId getId(const char *paStr, size_t paStrSize) const{
    unsigned int nIdx;
    return findEntry(paStr, paStrSize, nIdx);
  }
private:
  //!\brief Remove all dictionary entries
  void clear();

  // Find an exact match or place to be the new index
  TStringId findEntry(const char *paStr, unsigned int &paIdx) const;
  TStringId findEntry(const char *paStr, size_t paStrSize, unsigned int &paIdx) const;

  // Reallocate the buffer
  bool reallocateStringIdBuf(unsigned int pa_nNewMaxNrOfStrings);
  bool reallocateStringBuf(size_t pa_nNewBufSize);

  // Insert the string at the specified position
  TStringId insertAt(const char *pa_sStr, unsigned int pa_nIdx, size_t pa_nLen);

  // Get an address
  const char *getStringAddress(TStringId pa_nId) const {
    return m_paStringBufAddr + pa_nId;
  };

  char *getStringAddress(TStringId pa_nId) {
    return m_paStringBufAddr + pa_nId;
  };

  //!Buffer for the String Ids. The Ids are sorted according to their values they are pointing at
  TStringId *m_pnStringIdBufAddr;

  //! Buffer for the strings
  char *m_paStringBufAddr;

  // Size of the allocated space
  size_t m_nStringBufSize;

  // Maximum number of strings we can hold (size of the StringIdBufer)
  unsigned int m_nMaxNrOfStrings;

  // Number of strings we are actually holding
  unsigned int m_nNrOfStrings;

  // Next string gets written here
  TStringId m_nNextString;

#ifdef FORTE_STRING_DICT_FIXED_MEMORY
  static TStringId scm_aunIdList[cg_unStringDictInitialMaxNrOfStrings];
  static char scm_acConstStringBuf[cg_unStringDictInitialStringBufSize];
#else
  static const TStringId scm_aunIdList[];
  static const char scm_acConstStringBuf[];
#endif
};

#endif // _CStringDictionary_H_

