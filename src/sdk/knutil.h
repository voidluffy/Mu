/*
 * Copyright (C) Kreogist Dev Team
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef KNUTIL_H
#define KNUTIL_H

#include <QString>
#include <QColor>
#include <QDateTime>
#include <QStringList>
#include <QUrl>

/*!
 * \brief The KNUtil class cannot be construct. It will only used to provides
 * you several public static functions.
 */
class KNUtil
{
public:
    /*!
     * \brief Parse a color from a string. The format of the string can be: \n
     *  * RGB
     *  * #RGB
     *  * RRGGBB
     *  * #RRGGBB
     *  * RRGGBBAA
     *  * #RRGGBBAA
     * All the R, G, B and A above can be a hex number range 0-F.
     * \param data The color data string.
     * \return A QColor parsed from the string.
     */
    static QColor parseColor(const QString &data);

    /*!
     * \brief Simplified a file path. Sometimes the file path may be like:
     * /usr/bin//a, or /usr/bin/../bin/a. Both these path will be simplified to
     * /usr/bin/a.
     * \param path The file path.
     * \return The simplified file path.
     */
    static QString simplifiedPath(const QString &path);

    /*!
     * \brief This function will try to make the path valid.
     * \param path The prefer path.
     * \return The simplified path of the prefer path.
     */
    static QString ensurePathValid(const QString &path);

    /*!
     * \brief Use the system default file association to open a local file.
     * \param filePath The file path.
     */
    static void openLocalFile(const QString &filePath);

    /*!
     * \brief Show one file in graphical shell. Tried to locate that file in the
     * graphics user interface.
     * \param filePath The file path.
     */
    static void showInGraphicalShell(const QString &filePath);

    /*!
     * \brief Set text to system clipboard.
     * \param text The text.
     */
    static void setClipboardText(const QString &text);

    /*!
     * \brief Translate a local url list to file path string list.
     * \param urlList The local file url list.
     * \return The file path string list.
     */
    static QStringList urlListToPathList(const QList<QUrl> &urlList);

    /*!
     * \brief Change a string to a legal file name. This will change the file
     * name to Windows style. Means some character will be replaced to '_'.
     * \param fileName The original file name.
     * \return The file name which you can use under Windows.
     */
    static QString legalFileName(QString fileName);

    /*!
     * \brief Calculate the similarity between the two string. It will use
     * Sift-4 algorithm.
     * \param string1 The first string.
     * \param string2 The second string.
     * \return The quantized similiarity of two string. When they are the same,
     * it will return 0.
     */
    static int similarity(QString string1, QString string2);

    /*!
     * \brief Save text string to a local file via UTF-8 codec.
     * \param filePath The file path.
     * \param content The content data.
     * \return If the data writes successfully, return true.
     */
    static bool saveTextToFile(const QString &filePath,
                               const QString &content);

    /*!
     * \brief Rename a file to the new file name.
     * \param filePath The original file path.
     * \param newFileName The new name of the file.
     * \return If the file has been renamed successfully, return true.
     */
    static bool renameFile(const QString &filePath,
                           const QString &newFileName);

private:
    KNUtil();
    KNUtil(const KNUtil &);
};

#endif // KNUTIL_H
